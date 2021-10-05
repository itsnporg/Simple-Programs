const closestTo100 = (a,b) => (100-a) < (100-b) ? a: b;

console.log(closestTo100(36,54));
