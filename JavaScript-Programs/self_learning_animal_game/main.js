const getTreeRoot = require("./tree_structure"); //importing AnimalTree class tree root
const Node = require("./create_node"); //importing Node class
const readlineSync = require("readline-sync"); //importing readline-sync package
const fs = require("fs"); //importing node fs package

let root = getTreeRoot().returnRoot(); //taking this.root from AnimalTree class

//reading from json file
// const rawData = fs.readFileSync("./tree_data.json");
// const json = JSON.parse(rawData);

// if (Object.entries(json).length !== 0) root = json;

function main() {
  console.clear(); // clear console everytime user wants to play the game again
  console.log("Computer: Think of an animal");
  let current = root;

  //traversing the tree
  while (current !== undefined) {
    //when reached leaf node, then asking question
    if (current.yes === undefined && current.no === undefined) {
      if (
        current.text[0] === "A" ||
        current.text[0] === "E" ||
        current.text[0] === "I" ||
        current.text[0] === "O" ||
        current.text[0] === "U"
      )
        console.log(
          "Computer: Is it an " + current.text.toLowerCase() + "?" + " (yes/no)"
        );
      else
        console.log(
          "Computer: Is it a " + current.text.toLowerCase() + "?" + " (yes/no)"
        );

      let response = readlineSync.question("Human:\t");
      response = response.toLowerCase();

      if (response === "yes") console.log("Computer: Yay!  I got it!");
      else oopsINeedToImprove();

      break;
    }

    //if it's not leaf node, we will continue
    else {
      console.log("Computer: " + current.text + " (yes/no)");
      let response = readlineSync.question("Human:\t");
      response = response.toLowerCase();
      if (response === "yes") current = current.yes;
      else current = current.no;
    }
  }

  //do you want to play again?
  console.log("\nComputer: Want to play again? (yes/no)");
  let response = readlineSync.question("Human:\t");
  response = response.toLowerCase();
  if (response === "yes") main();
  else {
    console.log(
      "\nComputer: Thank you for playing the Animal Game\nComputer: Good bye!"
    );
    return;
  }

  //appending the tree if the animal is not present
  function appendTree(current, animalName, distinguish_question, answer) {
    let pointer = current.text;
    let temp = distinguish_question.split("");
    temp[0] = temp[0].toUpperCase();
    distinguish_question = temp.join("");
    current.text = distinguish_question;
    if (answer === "yes") {
      current.yes = new Node(animalName);
      current.no = new Node(pointer);
    } else {
      current.yes = new Node(pointer);
      current.no = new Node(animalName);
    }
  }

  //if the computer cannot guess the animal, it must improve
  function oopsINeedToImprove() {
    console.log("Computer: Oops - looks like I need to improve.");
    console.log("Computer: What is the animal?");
    let animalName = readlineSync.question("Human:\t"); //taking the new animal name to add to tree

    //display cases for animal names:
    if (
      (current.text[0] === "A" ||
        current.text[0] === "E" ||
        current.text[0] === "I" ||
        current.text[0] === "O" ||
        current.text[0] === "U") &&
      (animalName[0] === "A" ||
        animalName[0] === "E" ||
        animalName[0] === "I" ||
        animalName[0] === "O" ||
        animalName[0] === "U")
    )
      console.log(
        "Computer: What question would distinguish between an " +
          current.text.toLowerCase() +
          " and an " +
          animalName.toLowerCase() +
          "?"
      );
    else if (
      (current.text[0] === "A" ||
        current.text[0] === "E" ||
        current.text[0] === "I" ||
        current.text[0] === "O" ||
        current.text[0] === "U") &&
      (animalName[0] !== "A" ||
        animalName[0] !== "E" ||
        animalName[0] !== "I" ||
        animalName[0] !== "O" ||
        animalName[0] !== "U")
    )
      console.log(
        "Computer: What question would distinguish between an " +
          current.text.toLowerCase() +
          " and a " +
          animalName.toLowerCase() +
          "?"
      );
    else if (
      (current.text[0] !== "A" ||
        current.text[0] !== "E" ||
        current.text[0] !== "I" ||
        current.text[0] !== "O" ||
        current.text[0] !== "U") &&
      (animalName[0] === "A" ||
        animalName[0] === "E" ||
        animalName[0] === "I" ||
        animalName[0] === "O" ||
        animalName[0] === "U")
    )
      console.log(
        "Computer: What question would distinguish between a " +
          current.text.toLowerCase() +
          " and an " +
          animalName.toLowerCase() +
          "?"
      );
    else if (
      (current.text[0] !== "A" ||
        current.text[0] !== "E" ||
        current.text[0] !== "I" ||
        current.text[0] !== "O" ||
        current.text[0] !== "U") &&
      (animalName[0] !== "A" ||
        animalName[0] !== "E" ||
        animalName[0] !== "I" ||
        animalName[0] !== "O" ||
        animalName[0] !== "U")
    )
      console.log(
        "Computer: What question would distinguish between a " +
          current.text.toLowerCase() +
          " and a " +
          animalName.toLowerCase() +
          "?"
      );

    let distinguish_question = readlineSync.question("Human:\t");
    if (
      animalName[0] === "A" ||
      animalName[0] === "E" ||
      animalName[0] === "I" ||
      animalName[0] === "O" ||
      animalName[0] === "U"
    )
      console.log(
        "Computer: For an " +
          animalName.toLowerCase() +
          ', is the answer "yes" or "no"?'
      );
    else
      console.log(
        "Computer: For a " +
          animalName.toLowerCase() +
          ', is the answer "yes" or "no"?'
      );

    let answer = readlineSync.question("Human:\t");
    answer = answer.toLowerCase();
    appendTree(current, animalName, distinguish_question, answer);
    console.log("Computer: Thanks for helping me to improve!");
  }
}
main();

//writing in json file
const data = JSON.stringify(root);
console.log("\n" + data);
fs.writeFile("tree_data.json", data, (err) => {
  if (err) {
    throw err;
  }
  console.log("\nJSON data is saved.");
});
