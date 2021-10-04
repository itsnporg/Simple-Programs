// js code to get the fibonacci number of nth number of the series recursively. memoization included.

const fib = (n, memo = {}) => { 
  if (n in memo) return memo[n]; // checking if fibonacci of that number is already computed and returning the value if so
  if (n <= 2) return 1;
  memo[n] = fib(n-1, memo) + fib(n-2, memo); // fibonacci number of n is equal to the fibonacci of n-1 and n-2
  return memo[n]; 
};

console.log(fib(50));

// output : 12586269025
