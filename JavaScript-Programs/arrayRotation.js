// *shift function
// ! params : array , shiftIndices , shiftDirection [by default, set to left shift]
// ? pass a string ->'right' in the function params for right shift

const shift = (array, shiftIndices, shiftdirection) => {
  let indices = shiftIndices;

  // ? if shifTdirection is 'right' make a right shift of the indices specified
  if (shiftdirection === "right") {
    for (j = 0; j < indices; j++) {
      for (i = array.length - 1; i < array.length; i++) {
        var shiftedDigits = array.splice(i, 1);
        array.unshift(shiftedDigits[0]);
      }
    }
  }

  // ? ele left shift , default
  else {
    for (j = 0; j < indices; j++) {
      for (i = 0; i < 1; i++) {
        var shiftedDigits = array.splice(i, 1);
        array.push(shiftedDigits[0]);
      }
    }
  }

  return array;
};

module.exports = shift;
