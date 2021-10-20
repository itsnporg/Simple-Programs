// program to print(generate) a multiplication table of given integer

// taking input from the user
const number = parseInt(prompt('Enter an integer: '));

for(let i = 1; i <= 10; i++) {
    const result = i * number;

    console.log(`${number} * ${i} = ${result}. And Happy Hacktober!`);
}
