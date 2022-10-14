const mongoose = require("mongoose");

mongoose
  .connect(
    "mongodb://127.0.0.1:27017/mern-crud"
  )
  .then(() => {
    console.log("DAtabase connected");
  })
  .catch(() => {
    console.log("database is not connnected");
  });
