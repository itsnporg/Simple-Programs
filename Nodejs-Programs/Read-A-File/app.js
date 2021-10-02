// include file system module
let fs = require("fs");

// This reads the file named example.html
fs.readFile("example.html", function (err, data) {
  if (err) throw err;
  console.log(data.toString("utf8"));
});
