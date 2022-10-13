
const express = require("express");
const bodyParser = require("body-parser");
const ejs = require("ejs");
const _ = require("lodash");
const e = require("express");
const mongoose = require("mongoose")

mongoose.connect("YOUR_MONGO_URL", {useNewUrlParser: true});


const blogSchema = new mongoose.Schema({
  blogTitle: String,
  blogContent: String,
});

const blogModel = new mongoose.model("blogModel", blogSchema);

const homeStartingContent = "Welcome to my daily Blog. Create a beautiful blog that fits your style. Choose from a selection of easy-to-use templates – all with flexible layouts and hundreds of background images – or design something new.";
const aboutContent = "Hac habitasse platea dictumst vestibulum rhoncus est pellentesque. Dictumst vestibulum rhoncus est pellentesque elit ullamcorper. Non diam phasellus vestibulum lorem sed. Platea dictumst quisque sagittis purus sit. Egestas sed sed risus pretium quam vulputate dignissim suspendisse. Mauris in aliquam sem fringilla. Semper risus in hendrerit gravida rutrum quisque non tellus orci. Amet massa vitae tortor condimentum lacinia quis vel eros. Enim ut tellus elementum sagittis vitae. Mauris ultrices eros in cursus turpis massa tincidunt dui.";
const contactContent = "Scelerisque eleifend donec pretium vulputate sapien. Rhoncus urna neque viverra justo nec ultrices. Arcu dui vivamus arcu felis bibendum. Consectetur adipiscing elit duis tristique. Risus viverra adipiscing at in tellus integer feugiat. Sapien nec sagittis aliquam malesuada bibendum arcu vitae. Consequat interdum varius sit amet mattis. Iaculis nunc sed augue lacus. Interdum posuere lorem ipsum dolor sit amet consectetur adipiscing elit. Pulvinar elementum integer enim neque. Ultrices gravida dictum fusce ut placerat orci nulla. Mauris in aliquam sem fringilla ut morbi tincidunt. Tortor posuere ac ut consequat semper viverra nam libero.";

let app = express(); 

app.set('view engine', 'ejs');

app.use(bodyParser.urlencoded({extended: true}));
app.use(express.static("public"));

var posts =[];

app.get("/",(req,res)=>
{
  res.render("home", {startCont: homeStartingContent});
});

app.get("/posts", (req,res)=>
{
  res.render("post", {posts: posts});
});

app.get("/aboutus", (req,res)=>
{
  res.render("about", {aboutCont: aboutContent})
});

app.get("/contactme", (req,res)=>
{
  res.render("contact", {contactMe: contactContent})
});

app.get("/compose", (req,res)=>
{
  res.render("compose")
});

app.post("/compose", (req,res)=>
{
  const postM= new blogModel({
    blogTitle: req.body.postTitle,
    blogContent: req.body.postBody
  });
  
  const post= {
    title: req.body.postTitle,
    content: req.body.postBody
  };

  postM.save();
  posts.push(post)

res.redirect("/posts");
});

app.get("/posts/:postName", (req,res)=>
{

  const RequestednewPost = _.lowerCase(req.params.postName);

  for(var i=0;i<posts.length;i++)
  {
      
      const lowercasePosts= _.lowerCase(posts[i].title);

      if(RequestednewPost===lowercasePosts)
      {
        res.render("posting", {
         
           title: posts[i].title,
           content: posts[i].content

        });
      }
  }

});

app.listen(process.env.PORT || 5000, function() {
  console.log("Server started on port 5000");
});
