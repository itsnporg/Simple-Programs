/* 
Code: Guess the random number
*/

// function whose generator random number
function generateNumber(min = 0, max = 100) {
  min = Math.floor(min);
  max = Math.ceil(max);
  return Math.ceil(Math.random() * (max - min) + min);
}

const generatedNumber = generateNumber();

// Let this is input Value
const inputNumber = 55; // change is this hard code value to html input value

// check the condition where the number matches or lower or greater
function checkInput(inputNumber) {
  if (inputNumber < generatedNumber)
    return `Your guess is wrong. Value is greater than ${inputNumber}.`;
  if (inputNumber > generatedNumber)
    return `Your guess is wrong. Value is less than ${inputNumber}.`;
  if (inputNumber == generatedNumber)
    return `Your guess is correct. Value is ${inputNumber}.`;
}

console.log(checkInput(inputNumber));
