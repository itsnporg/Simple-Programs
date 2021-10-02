// file system module to perform file operations
const fs = require("fs");

const jsonData = {
  name: "ITSNP",
  age: 1,
  period: "years",
  rating: "5/5",
};

console.log(jsonData.name); // ITSNP

console.log(jsonData.rating); // 5/5
jsonData.rating = "100/100";
console.log(jsonData.rating); // 100/100

console.log(jsonData["age"]); // 1

const jsonContent = JSON.stringify(jsonData);

fs.writeFile("output.json", jsonContent, "utf8", function (err) {
  if (err) {
    console.log("An error occured while writing JSON Object to File.");
    return console.log(err);
  }

  console.log("JSON file has been saved.");
});
