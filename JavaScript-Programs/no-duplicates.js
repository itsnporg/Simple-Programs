const arr = [1, 5, 2, 3, 2, 2, 2, 3, 2, 6, 7];
const no_duplicates_arr = []; 
arr.forEach((value) => {
	if (no_duplicates_arr.indexOf(value) === -1) {
		no_duplicates_arr.push(value);
	};
});
console.log(no_duplicates_arr); // [ 1, 5, 2, 3, 6, 7 ]

