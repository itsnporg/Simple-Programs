// program to find the largest number among two given numbers

// take input from the user
const num1 = parseFloat(prompt("Enter first number: "));
const num2 = parseFloat(prompt("Enter second number: "));

// check the condition
if(num1 >= num2) {
    console.log("The largest number is " + num1);
}
else if (num2 >= num1) {
    console.log("The largest number is " + num2);
} else {
    console.log("Invalid Input: Error 404");
}
