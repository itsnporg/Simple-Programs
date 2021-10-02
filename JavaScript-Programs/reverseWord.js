// JavaScript program(s) to reverse a string in two ways

// ? npm pack for CLI-interface
const readlineSync = require("readline-sync");

// TODO : reverse word using simple for loop
const reverseWord = (word) => {
  //* create an emptyy array to store the user input
  let arr = [];
  // * run a for loopto loop through the user input word
  for (i = 0; i < word.length; i++) {
    // * for each iteration push the value in the arr, created
    arr.push(word[i]);
  }
  console.log(arr.reverse().join(""));
};

// TODO : using methods
const mirrorWords = (word) => {
  // ! step1: turn the word(string) into a array of chars using the split method
  // * sample out put = ['h','e' , 'l', 'l', 'o']
  let slices = word.split("");

  // ! Step2 : to reverse the array of strings, use reverse() method
  //* sample : ['o', 'l', 'l', 'e', 'h']

  // ! join the array of strings using the join operator. alterateively you can also use tostring() method
  let reversed = slices.reverse().join("");

  return reversed;
};

console.log(mirrorWords(engineer));
