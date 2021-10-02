const mongoClient = require("mongodb").MongoClient;
const url = "mongodb://localhost:27017/";

mongoClient.connect(url, function (err, db) {
  if (err) throw err;
  var dbo = db.db("mydb");
  dbo.createCollection("customers", function (err, res) {
    if (err) throw err;
    console.log("Collection created!");
    db.close();
  });
});
