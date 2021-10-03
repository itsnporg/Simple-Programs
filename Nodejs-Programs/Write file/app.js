const { promises: fs } = require("fs");

const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

// promisify fungsi rl.question
const question = (query) =>
  new Promise((resolve) => rl.question(query, resolve));

const run = async () => {
  try {
    const input = await question(
      "Menu \n 1. Write file \n 2. Read file \n\n Choose menu : "
    );
    if (input == 1) {
      const nama = await question("Enter your name : ");
      const umur = await question("Enter your age : ");
      const biodata = { nama, umur };

      const rawData = await fs.readFile("data/file.json", "utf-8");
      const data = JSON.parse(rawData);
      data.push(biodata);

      await fs.writeFile("data/file.json", JSON.stringify(data));
      console.log("Berhasil menulis file");
    } else if (input == 2) {
      const data = await fs.readFile("data/file.json", "utf-8");
      console.log(JSON.parse(data));
    }
    rl.close();
  } catch (err) {
    console.error("Terjadi kesalahan: ", err);
  }
};

run();
