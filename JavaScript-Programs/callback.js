// Program demonstrating callback functions in Javascript

const modifyArray = (arr, callback) => {
  arr.push(6);
  callback();
};

const arr = [1, 2, 3, 4, 5];

modifyArray(arr, () => {
  console.log("Array has been modified", arr);
});
