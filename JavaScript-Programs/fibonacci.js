const fibonacciSequence = (number) => {
  for (
    var fibonacci = [0, 1], i = 1;
    i < number;
    i++ // Starts array at index [0, 1] (1).
  )
    fibonacci.push(fibonacci[i] + fibonacci[i - 1]); // Pushes current index + previous index (current index -1).

  return console.log(fibonacci); // Returns array of fibonacciSequence.
};

fibonacciSequence(50); // How many numbers you want to output... E.G fibonacciSequence(10) = 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55.
