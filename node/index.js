const express = require('express');
const bodyParser = require('body-parser')
const dotenv = require('dotenv');
const fs = require('fs');
const path = require('path');

dotenv.config();

const { BASE_EXECUTE } = process.env;

const PORT = 3030;

const app = express();

const options = {
	inflate: true,
	limit: '100mb',
	type: 'application/octet-stream'
  };
app.use(bodyParser.raw(options));

/*

  data = https://dajskl.dsa - set new server url
  duration-5 set request duration to 5 seconds
*/

app.post("/", (req, res) => {
	console.log(req.body.toString());
	res.set('Content-Type', 'application/json');
	const data = fs.readFileSync(path.resolve(__dirname, `../source/usr/base/build/${BASE_EXECUTE}`));
	res.send(data);
});

app.listen(PORT, () => {
	console.info(`Running at port: ${PORT} ...`);
});
