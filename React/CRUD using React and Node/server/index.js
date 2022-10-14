const express = require("express");
const app = express();
require("./db-connection/conn");
const User = require("./model/userSchema");
const cors = require("cors");

app.use(express.json());
app.use(cors());
const port = process.env.PORT || 8000;

app.post("/add", async (req, res) => {
  try {
    const user = new User({
      name: req.body.name,
      username: req.body.username,
      email: req.body.email,
      phoneno: req.body.phoneno,
    });
    await user.save();
    res.send("data is inserted");
  } catch (error) {
    console.log(error.errors.name.properties.message);
    res.status(400).send(error.errors.name.properties.message);
  }
});

app.get("/", async (req, res) => {
  try {
    const users = await User.find();
    res.status(200).json(users);
  } catch (error) {
    console.log(error);
  }
});

app.get("/edit/:id", async (req, res) => {
  try {
    const user = await User.findById(req.params.id);
    // console.log(user);
    // !user && res.status(400).json({ err: "no user" });
    res.status(200).json(user);
  } catch (err) {
    console.log(err);
  }
});

app.put("/edit/:id", async (req, res) => {
  try {
    const updatedUser = await User.findByIdAndUpdate(req.params.id, req.body, {
      new: true,
    });
    // console.log(updatedUser);
    res.status(200).json(updatedUser);
  } catch (error) {
    console.log(error);
  }
});

app.delete("/:id", async (req, res) => {
  try {
    const deleteUser = await User.findByIdAndDelete(req.params.id);
    // console.log(deleteUser);
  } catch (error) {
    console.log(error);
  }
});

app.listen(port, () => {
  console.log(`Listening at port ${port} `);
});
