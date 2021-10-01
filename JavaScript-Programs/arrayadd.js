//adds elements of two arrays simultaneously

const carry = [];
const sum = [];
const l1 = []; //first array, insert values here
const l2 = []; //second array, insert values here

let forLength = 0;
//checking for the array with greater length
if (l1.length > l2.length) {
  forLength = l1.length;
} else if (l1.length < l2.length) {
  forLength = l2.length;
} else {
  forLength = l1.length;
}

//for loop that goes through all the elements of both arrays simultaneously
for (let i = 0; i < forLength; i++) {
  //checking if index of the current element is 0 or not.

}

console.log(sum);
