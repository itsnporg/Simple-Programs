// js code to check if a number is palindrome or not along with a reverse function

const x = prompt('Enter a positive integer')


//defining a reverse function
var reverse = function(y) {
  if (y >= Math.pow(2, 31)-1 || y<= Math.pow(-2, 31)) return 0;
  revsum = 0;
  checkSign = Math.sign(y);
  if (checkSign === -1) {
    y = y*-1;
  }
  var myArr = String(y).split("").map((y)=>{
    return Number(y)
  })
  for (var i = myArr.length - 1; i >= 0; i=i-1) {
    const num = myArr[i]*Math.pow(10, i)
    revsum = revsum + num
  }
  if (revsum >= Math.pow(2, 31)-1 || revsum<= Math.pow(-2, 31)) return 0;
  return revsum*checkSign;
};

rev = reverse(x);

//checking if reverse equals given integer
if (rev === x) {
  console.log(`${x} is a palindrome number`);
} else {
  console.log(`${x} is not a palindrome number`);
}


