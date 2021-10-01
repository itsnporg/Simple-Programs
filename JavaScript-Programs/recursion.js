// Recursion is a process of calling itself.
// function recurse() {
//     if(condition) {
//         recurse();
//     }
//     else {
//         stop calling recurse()
//     }
// }

// recurse();

// Program of Recursion

// program to count down numbers to 1
const countDown = (number) => {
  // display the number
  console.log(number);

  // decrease the number value
  const newNumber = number - 1;

  // base case
  newNumber > 0 && countDown(newNumber);
};

countDown(6);

// Output
// 6
// 5
// 4
// 3
// 2
// 1
