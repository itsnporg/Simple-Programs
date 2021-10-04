// program to solve quadratic equation using javascript
//first of all we request user for the number that are in the equation as
let root1, root2;

// take input from the user
let a = prompt("Enter the first number: ");
let b = prompt("Enter the second number: ");
let c = prompt("Enter the third number: ");

// calculate discriminant for finding later on roots
let discriminant = b * b - 4 * a * c;

// condition for real and different roots as per our teacher
if (discriminant > 0) {
    root1 = (-b + Math.sqrt(discriminant)) / (2 * a);
    root2 = (-b - Math.sqrt(discriminant)) / (2 * a);

    // result
    console.log(`The roots of quadratic equation are ${root1} and ${root2}`);
}

// condition for real and equal roots
else if (discriminant == 0) {
    root1 = root2 = -b / (2 * a);

    // result
    console.log(`The roots of quadratic equation are ${root1} and ${root2}`);
}

// if roots are not real
else {
    let realPart = (-b / (2 * a)).toFixed(2);
    let imagPart = (Math.sqrt(-discriminant) / (2 * a)).toFixed(2);

    // result
    console.log(
    `The roots of quadratic equation are ${realPart} + ${imagPart}i and ${realPart} - ${imagPart}i`
  );
}
