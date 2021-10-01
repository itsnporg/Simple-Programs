const array = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
console.log(`Original: ${array.join(", ")}`);
// -> Original: 1, 2, 3, 4, 5, 6, 7, 8, 9, 10

const shuffled = array.sort(() => 0.5 - Math.random());
console.log(`Shuffled: ${shuffled.join(", ")}`);
// -> Shuffled: 5, 3, 1, 6, 4, 8, 10, 7, 9, 2
