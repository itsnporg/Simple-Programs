const fruits = ["apple", "banana", "orange", "banana"];

const getUniqueItemsInArray = (arr) => [...new Set(fruits)];

const uniqueFruits = getUniqueItemsInArray(fruits);
