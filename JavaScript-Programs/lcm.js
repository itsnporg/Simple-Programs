// program to find the LCM of two given integers

// TAKING THE HCF OF THE NUMBERS
let hcf;

const num1 = prompt('Enter a first positive integer: ');
const num2 = prompt('Enter a second positive integer: ');

for (let i = 1; i <= num1 && i <= num2; i++) {
    if( num1 % i == 0 && num2 % i == 0) {
        hcf = i;
    }
}

// FINDING THE LCM USING THE HCF

let lcm = (num1 * num2) / hcf;

// display the lcm
console.log(`LCM of ${num1} and ${num2} is ${lcm}. And Happy Hacktober!`);
