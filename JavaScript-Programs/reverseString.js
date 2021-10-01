// a JavaScript program to reverse a string

const reverse = (text) => {
  return text.toString().split("").reverse().join("");
};

console.log(reverse("hello world")); // dlrow olleh
console.log(reverse(12345)); // 54321

// Explanation

// toString()  method converts the supplied input into string type.
// split('') method converts string into an array of letters. For eg. "hello".split("")  will return ['h','e','l','l','o']
// reverse() method reverses an array
// join() method joins all the elements of an array into a string. For eg. ['h','e','l','l','o'].join("") will return "hello"

// combining them all, we get our string reversed
