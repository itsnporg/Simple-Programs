var num1 = prompt("enter num1"); // declare first number
var num2 = prompt("enter num2"); // declare second number
  // function that return minimum number
function min(num1, num2) {
 // conditional statement checking for min number
     if (num1 < num2) {
         return num1
     }
     else {
         return num2
     }
 }
 console.log(min(num1,num2));