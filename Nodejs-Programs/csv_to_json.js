const fs = require("fs");
const path = require("path");

const csvToJson = (csv) => {
  const lines = csv.trim().split("\n");

  const result = [];

  const headers = lines[0].trim().split(",");

  lines.forEach((ele, index) => {
    if (index < 1) return;

    const obj = {};

    const currentLine = lines[index].trim().split(",");

    headers.forEach((ele, index) => {
      obj[headers[index]] = currentLine[index];
    });

    result.push(obj);
  });

  result.pop();

  result.forEach((ele) => {
    if (ele["age"]) {
      ele["age"] = parseInt(ele["age"]);
    }
  });

  fs.writeFileSync("output.json", JSON.stringify(result));
};

if (process.argv[2]) {
  const filePath = path.join("../", process.argv[2]);

  const csv = fs.readFileSync(filePath, { encoding: "utf-8" });
  if (csv) {
    csvToJson(csv);
  }
} else {
  console.log("Csv file not found");
}