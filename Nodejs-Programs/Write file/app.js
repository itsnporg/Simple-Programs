const { promises: fs } = require("fs");

const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

const question = (query) =>
  new Promise((resolve) => rl.question(query, resolve));

const run = async () => {
  try {
    const input = await question(
      "Menu \n 1. Write file \n 2. Read file \n\n Choose menu : "
    );
    if (input == 1) {
      const name = await question("Enter your name : ");
      const age = await question("Enter your age : ");
      const biodata = { name, age };

      const rawData = await fs.readFile("data/file.json", "utf-8");
      const data = JSON.parse(rawData);
      data.push(biodata);

      await fs.writeFile("data/file.json", JSON.stringify(data));
    } else if (input == 2) {
      const data = await fs.readFile("data/file.json", "utf-8");
    }
    rl.close();
  } catch (err) {
    console.error("Error: ", err);
  }
};

run();
