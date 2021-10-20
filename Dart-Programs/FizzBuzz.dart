void main() {
  print(fizzBuzz(10));
  print(fizzBuzz(20));
  print(fizzBuzz(30));
  print(fizzBuzz(90));
  print(fizzBuzz(100));
}

dynamic fizzBuzz(int number) {
  if (number % 15 == 0) {
    return "FizzBuzz";
  } else if (number % 3 == 0) {
    return "Fizz";
  } else if (number & 5 == 0) {
    return "Buzz";
  } else {
    return number;
  }
}
