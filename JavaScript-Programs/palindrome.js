// js code to check if a number is palindrome or not along with a reverse function

const number = prompt('Enter a positive integer')


//defining a reverse function
const reverse = function(y) {
  rev_num = 0;
  let num_to_Array = String(y).split("").map((y)=>{
    return Number(y)
  })
  for (let i = num_to_Array.length - 1; i >= 0; i=i-1) {
    const num = num_to_Array[i]*Math.pow(10, i)
    rev_num = rev_num + num
  }
};

rev = reverse(number);

//checking if reverse equals given integer
if (rev === number) {
  console.log(`${number} is a palindrome number`);
} else {
  console.log(`${number} is not a palindrome number`);

