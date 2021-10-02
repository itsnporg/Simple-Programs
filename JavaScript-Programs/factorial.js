//program to find factorial of a number
// input : 4 :: 4 x 3 x 2 x 1
//input : 0 :: o/p --> 1

let factorial = (num) => {
  // ! check if number is 0 , then return 1 if true
  if (num === 0) {
    return 1;
  } else {
    // * if positive, run a recurive function
    return num * factorial(num - 1);
  }
};

//o/p
console.log(factorial(4)); // 4 x 3 x 2 x 1 = 24
