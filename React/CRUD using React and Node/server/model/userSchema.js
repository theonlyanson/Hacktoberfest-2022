const mongoose = require("mongoose");
const validatr = require("validator");

const userSchema = new mongoose.Schema({
  name: {
    type: String,
    require: true,
    unique: [true, "Please Enter unique Name"],
    minlength: [3, "name should be greater than 3 letter"],
  },
  username: {
    type: String,
    require: true,
    unique: [true, "Please Enter unique userName"],
  },
  email: {
    type: String,
    require: true,
    validator(value) {
      if (!validatr.isEmail(value)) {
        console.log("Please Enter valid Email Format");
      }
    },
  },
  phoneno: {
    type: Number,
    require: true,
    unique: [true, "Please Enter unique 10 digit phone Number"],
    min: 999999999,
    max: 9999999999,
  },
});

const User = new mongoose.model("New-crud", userSchema);

module.exports = User;
