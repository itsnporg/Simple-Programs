// createPhoneNumber([1, 2, 3, 4, 5, 6, 7, 8, 9, 0]) // => returns "(123) 456-7890"

function createPhoneNumber(numbers) {
	let num = [];
	for (let i = 0; i < numbers.length; i++) {
		if (i == 0) {
			num.push("(");
		} else if (i == 3) {
			num.push(") ");
		} else if (i == 6) {
			num.push("-");
		}
		num.push(numbers[i]);
	}
	return num.join("");
}
