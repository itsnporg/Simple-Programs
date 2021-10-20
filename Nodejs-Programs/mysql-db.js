const mysql = require('mysql');
 
const con = mysql.createConnection({
  host: "localhost",
  user: "username",
  password: "password"
});
 
// connect to the database.
con.connect(function(err) {
  if (err) throw err;
  console.log("Connected!");
});

function select() {
  con.query("SELECT * FROM students", function (err, result, fields) {
    if (err) console.log(err);
    console.log(result);
  }
}
            
function insert() {
  con.query("INSERT INTO students (name,rollno,marks) values ('Student',12,95)", function (err, result, fields) {
    if (err) console.log(err);
    console.log(result);
  }
}
            
function update() {
  con.query("UPDATE students SET marks=84 WHERE marks=74", function (err, result, fields) {
    if (err) console.log(err);
    console.log(result);
  }
}
            
function delete() {
  con.query("DELETE FROM students WHERE rollno>10", function (err, result, fields) {
    if (err) console.log(err);
    console.log(result);    
  }
}
