const express = require('express');
var bodyParser = require('body-parser')
const fs = require('fs');
const path = require('path');

const PORT = 3030;

const app = express();
app.use(bodyParser.json());


app.post("/", (req, res) => {
	console.log(req.data);
	res.set('Content-Type', 'application/json');
	const data = fs.readFileSync(path.resolve(__dirname, '../source/usr/base/build/response'));
	res.send(data);
});

app.listen(PORT, () => {
	console.info(`Running at port: ${PORT} ...`);
});
