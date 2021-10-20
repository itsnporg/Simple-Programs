// Currying -> f(N) => f(1)

const add = (a) => (b) => a + b;
const sum = add(1)(2);
console.log(sum);
