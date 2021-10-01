//adds elements of two arrays simultaneously


  const carry=[];
  const sum=[];

  //checking for the array with greater length 
  if (l1.length > l2.length) {
   let forLength = l1.length; 
  }
  else if (l1.length < l2.length) {
    let forLength = l2.length;
  }
  else {
    let forLength = l1.length;
  }

  //for loop that goes through all the elements of both arrays simultaneously
  for (let i = 0; i < forLength; i++) {

      //checking if index of the current element is 0 or not.
      if (i === 0) {
          carrynum = 0
      } else {
          carrynum = carry[i-1];
      }

      //checking if current element of at least one array is present or if it is 0
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

      // appending to sum and carry array
      let sumArr = String(sumNum).split("").map((sumNum)=>{
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
