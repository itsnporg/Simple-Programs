//adds elements of two arrays simultaneously


  const carry=[]; //carry array 
  const sum=[]; //array to push sums to

  //checking for the array with greater size 
  if (l1.length > l2.length) {
   var forLength = l1.length; 
  }
  else if (l1.length < l2.length) {
      var forLength = l2.length;
  }
  else {
      var forLength = l1.length;
  }

  //for loop that goes through simultaneous elements of both arrays
  for (var i = 0; i < forLength; i++) {

      //checking if elements are the first or not and assigning value of carry from the array
      if (i === 0) {
          carrynum = 0
      } else {
          carrynum = carry[i-1];
      }

      //checking if both or one of the elements are present and also if the element is 0
      if (l1[i] && l2[i]){ 
          sumNum = l1[i] + l2[i] + carrynum
      } else if (l1[i] && !l2[i]) {
          sumNum = l1[i] + carrynum 
      } else if (!l1[i] && l2[i]) {
          sumNum = l2[i] + carrynum 
      } 
      else {
          sumNum = 0;
      }

      // basically pushes the sum and carry to their arrays
      var sumArr = String(sumNum).split("").map((sumNum)=>{
          return Number(sumNum)
      })
      if (sumArr.length === 2) {
          carry.push(sumArr[0]);
          sum.push(sumArr[1]);
      } else {
          carry.push(0);
          sum.push(sumArr[0]);  
      }
  }

console.log(sum);
