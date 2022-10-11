const express = require("express");

require('dotenv').config();

const app = express();


const ejs = require("ejs");


app.set("view engine", "ejs");

app.use(express.static("public"));

const bodyParser = require("body-parser");

const mongoose = require("mongoose");

const encrypt = require("mongoose-encryption");

mongoose.connect("YOUR_MONGO_ID_HERE");

app.use(bodyParser.urlencoded({ extended: true }));

const UserSchema = new mongoose.Schema ({
  mail: { type: String, required: true },
  password: { type: String, required: true },
  passwords:[String],
  websites:[String],
});

const secret = process.env.SECRET;

UserSchema.plugin(encrypt,{secret:secret, encryptedFields:["password","passwords"]});

const User = mongoose.model("user", UserSchema);

app.get("/", (req, res) => {
  res.render("intro");
});

app.get("/register", (req, res) => {
  res.render("register",{title:"Register"});
});
app.get("/login", (req, res) => {
  res.render("login",{title:"Login"});
});
app.post("/register", (req, res) => {
  const pwd = (req.body.password);
  const username = req.body.email;
  const user = new User({
    password: pwd,
    mail: username,
  });
  user.save();
  res.render("passwords",{name:username});
});
app.post("/login", (req, res) => {
  const name = req.body.email;
  const Promise = User.findOne({mail: name}).exec();
  Promise.then(doc=>{
  const pwd = (req.body.password);
    if(pwd===doc.password){
        res.render("passwords",{name:name});
    }
  }).catch(err=>{
    console.log(err);
  });
  
});
app.post("/passwords",(req,res)=>{
  const name = req.body.name;
  const encrypt = (req.body.password);
  User.findOne({mail:name},(err,result)=>{
    if(err){
      console.log(err);
    }
    else{
      result.passwords.push(encrypt);
      result.websites.push(req.body.website);
      result.save();
      res.render("Success",{name:name});
    }
  });

});
app.post("/success",(req,res)=>{
  const name = req.body.name;
  res.render("passwords",{name:name});
});
app.get("/loginpass",(req,res)=>{
  res.render("loginpass"); 
})
app.post("/loginpass",(req,res)=>{
  const email = req.body.name;
  
  User.findOne({mail:email},(err,result)=>{
    if(err){
      console.log(err);
    }
    else{
      const websites = result.websites;
      const passwords = result.passwords;
      res.render("showpass",{websites:websites,passwords:passwords});
    }
  })
})
app.listen(process.env.PORT||3000, () => {
  console.log("listening to port 3000");
});
