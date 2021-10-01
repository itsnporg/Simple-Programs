// program to find the factors of an integer

const num = prompt('Enter a positive number: ');

console.log(`The factors of ${num} is: `);

for(let i = 1; i <= num; i++) {
    if(num % i == 0) {
        console.log(i + " ");
    }
}
