const express = require('express');
const app = express();
const port = 3000;

app.get('/', (req, res) => {
  res.send('Hello World!');
})

const echoRouter = require('./routes/echo');
app.use('/echo', echoRouter);

app.listen(port, () => {
  console.log(`Example app listening on port ${port}`)
})

const process = require('process');
const db = require('./models/db.js');
process.on('SIGINT', db.cleanup)
process.on('SIGTERM', db.cleanup)