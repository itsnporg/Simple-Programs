const fizzBuzz = (input) => {
  if (typeof input != "number") return NaN;

  if (input % 3 && input % 5 === 0) return "FizzBuzz";

  if (input % 3 === 0) return "Fizz";

  if (input % 5 === 0) return "Buzz";

  return input;
};

const output = fizzBuzz(15);
console.log(output);
