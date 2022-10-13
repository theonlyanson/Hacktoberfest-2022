const uuid = require("uuid").v4;
const express = require("express");
const dotenv = require("dotenv");
dotenv.config();
const multer = require("multer");
const app = express();
const AWS = require("aws-sdk");

// note : i have removed aws server credentials so keep it mind before test

const s3 = new AWS.S3({
  accessKeyId: process.env.AWS_ID,
  secretAccessKey: process.env.AWS_SECRET,
  region: process.env.AWS_BUCKET_REGION,
});

const storage = multer.memoryStorage({
  destination: function (req, file, callback) {
    callback(null, "");
  },
});

const upload = multer({ storage }).single("image");

//only for file uploading with aws and multer
app.post("/upload", upload, (req, res) => {
  const myFile = req.file.originalname.split(".");
  const fileType = myFile[myFile.length - 1];

  //   console.log(req.file);
  //   res.send({ message: "Hello Wworld" });

  const params = {
    Bucket: process.env.AWS_BUCKET_NAME,
    Key: `userName/${uuid()}.${fileType}`,
    Body: req.file.buffer,
    ACL: "public-read",
  };

  s3.upload(params, (err, data) => {
    if (err) {
      res.status(500).json(error);
    }
    res.status(200).json(data);
  });
});

//only for file collecting from aws  server

app.get("/getall", (req, res) => {
  const params = {
    Bucket: process.env.AWS_BUCKET_NAME, // it is use for get whole aws data just by diclaring bucket name

    // it is use for particular folder data
    Delimiter: "/",
    Prefix: "username/",
  };

  s3.listObjects(params, (err, data) => {
    if (err) {
      res.status(500).json(err);
    }
    res.status(200).json(data);
  });
});

// it is use for limited time link available for watching the image
app.post("/presigned", upload, (req, res) => {
  const url = s3.getSignedUrl("getObject", {
    Bucket: process.env.AWS_BUCKET_NAME,
    Key: "username/b54577d8-7d1c-4559-94f8-e5632458c000.jpg",
    Expires: 10,
  });

  res.status(200).json(url);
});

// file upload with limited time valid url
app.post("/uploadwithsigned", upload, (req, res) => {
  const myFile = req.file.originalname.split(".");
  const fileType = myFile[myFile.length - 1];
  const fileKey = `username/${uuid()}.${fileType}`;

  const params = {
    Bucket: process.env.AWS_BUCKET_NAME,
    Key: fileKey,
    Body: req.file.buffer,
    ACL: "public-read",
  };

  s3.upload(params, (err, data) => {
    if (err) {
      res.status(500).json(error);
    }
    res.status(200).json(data);
  });

  const url = s3.getSignedUrl("getObject", {
    Bucket: process.env.AWS_BUCKET_NAME,
    Key: fileKey,
    Expires: 10,
  });
});

//deleting object from AWS
app.delete("/deleteobject", async (req, res) => {
  const params = {
    Bucket: process.env.AWS_BUCKET_NAME,
    Key: "username/6a41a6fc-d6eb-4a7d-946a-62d75b6a1399.jpg",
  };

  s3.deleteObject(params, (err, data) => {
    if (err) res.status(400).json(err);

    res.status(200).json({ message: "Object deleted" });
  });
});

app.listen(8000, () => {
  console.log("server started at port 8000");
});
