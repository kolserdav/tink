const express = require('express');
var bodyParser = require('body-parser')
const fs = require('fs');
const path = require('path');

const PORT = 3030;

const app = express();

const options = {
	inflate: true,
	limit: '100mb',
	type: 'application/octet-stream'
  };
app.use(bodyParser.raw(options));


app.post("/", (req, res) => {
	console.log(req.body.toString());
	console.log(req.headers);
	res.set('Content-Type', 'application/json');
	const data = fs.readFileSync(path.resolve(__dirname, '../source/usr/base/build/response'));
	res.send(data);
});

app.listen(PORT, () => {
	console.info(`Running at port: ${PORT} ...`);
});
