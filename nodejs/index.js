const express = require('express');
const app = express();
const port = process.env.PORT || 3030;
const apiData = require('./data.json')
const cors = require('cors')

app.use(cors());

app.get('/', function(req, res){
  res.send("ACTION")
})
app.get('/mobiles',function(req, res){
  res.send(apiData)
})

app.listen(port,()=>{ console.log("live");})