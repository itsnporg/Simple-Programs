//Input Query Selection
const input_system = document.querySelector("#input-type");
const input_value = document.querySelector("#input-textarea");
const input_type_label = document.querySelector("#input-label");

//Output Query Selection
const output_label_1 = document.querySelector("#output-label-1");
const output_label_2 = document.querySelector("#output-label-2");
const output_label_3 = document.querySelector("#output-label-3");

const output_value_1 = document.querySelector("#output-value-1");
const output_value_2 = document.querySelector("#output-value-2");
const output_value_3 = document.querySelector("#output-value-3");

//Other Query Selection
const alert_message = document.querySelector(".alert-message");
const form = document.querySelector("#form");

//Event Listener for the from submission.
form.addEventListener("submit", (e) => {
  e.preventDefault();
  if (input_system.value == "") {
    addAlert("danger", "Please choose a input system", true, 3);
    input_system.classList.add("bg-alert-red");
  } else {
    switch (parseInt(input_system.value)) {
      case 1:
        //   //console.log("I am binary");
        if (verifyBinary(input_value.value)) {
          output_value_1.innerHTML = binarytodecimal(input_value.value);
          output_value_2.innerHTML = binarytooctal(input_value.value);
          output_value_3.innerHTML = binarytohexadecimal(input_value.value);
        } else {
          addAlert("danger", "No valid binary number provided.", true, 5);
          input_value.classList.add("bg-alert-red");
        }
        break;
      case 2:
        // //console.log("I am decimal");
        if (verifyDecimal(input_value.value)) {
          output_value_1.innerHTML = decimaltobinary(input_value.value);
          output_value_2.innerHTML = decimaltooctal(input_value.value);
          output_value_3.innerHTML = decimaltohexadecimal(input_value.value);
        } else {
          addAlert("danger", "No valid decimal number provided.", true, 5);
          input_value.classList.add("bg-alert-red");
        }
        break;
      case 3:
        // //console.log("I am octal");
        if (verifyOctal(input_value.value)) {
          output_value_1.innerHTML = octaltobinary(input_value.value);
          output_value_2.innerHTML = octaltodecimal(input_value.value);
          output_value_3.innerHTML = octaltohexadecimal(input_value.value);
        } else {
          addAlert("danger", "No valid octal number provided.", true, 5);
          input_value.classList.add("bg-alert-red");
        }
        break;
      case 4:
        // //console.log("I am hexadecimal");
        if (verifyHexaDecimal(input_value.value)) {
          output_value_1.innerHTML = hexadecimaltobinary(input_value.value);
          output_value_2.innerHTML = hexadecimaltodecimal(input_value.value);
          output_value_3.innerHTML = hexadecimaltooctal(input_value.value);
        } else {
          addAlert("danger", "No valid hexadecimal number provided.", true, 5);
          input_value.classList.add("bg-alert-red");
        }
        break;

      default:
        break;
    }
  }
});

input_value.addEventListener("click", () => {
  input_value.classList.remove("bg-alert-red");
});

function clearAlert(id, time) {
  setTimeout(() => {
    ////console.log(`Alert with id {${id}} Cleared..`);
    if (alert_message.innerHTML != "") {
      document.querySelector(`#${id}`).remove();
    }
  }, time * 1000);
}

function addAlert(mode, message, autodismiss, clearTime) {
  let id = "alert-" + Math.floor(Math.random() * 10000000);
  let content = `<div class="alert `;
  if (mode == "success") {
    content = content.concat(`alert-success `);
  } else if (mode == "danger") {
    content = content.concat(`alert-danger `);
  }
  content = content.concat(`alert-dismissible fade show" role="alert" id=${id}>
        <strong> ${message}</strong>
        <button type="button" class="close" data-dismiss="alert"
            aria-label="Close">
            <span aria-hidden="true">&times;</span>
        </button>
    </div>`);
  alert_message.innerHTML += content;
  if (autodismiss == true) {
    clearAlert(id, clearTime);
  }
  //Clear Function.
  function clearAlert(id, time) {
    setTimeout(() => {
      ////console.log(`Alert with id {${id}} Cleared..`);
      if (alert_message.innerHTML != "") {
        document.querySelector(`#${id}`).remove();
      }
    }, time * 1000);
  }
}

function clearValue() {
  ////console.log("I am clearing ..");
  input_value.value = "";
  output_value_1.innerHTML = "";
  output_value_2.innerHTML = "";
  output_value_3.innerHTML = "";
  addAlert("success", "Value reset successful", true, 2);
}
//Change Labels on the basis of input system selection.
input_system.addEventListener("change", () => {
  input_system.classList.remove("bg-alert-red");
  input_value.classList.remove("bg-alert-red");
  output_value_1.classList.remove("bg-alert-red");
  output_value_2.classList.remove("bg-alert-red");
  output_value_3.classList.remove("bg-alert-red");
  switch (parseInt(input_system.value)) {
    case 1:
      ////console.log("Input selected as binary");
      input_type_label.innerHTML = "Binary Number ( Base 2) :";
      output_label_1.innerHTML = "Decimal Number ( Base 10 ) :";
      output_label_2.innerHTML = "Octal Number ( Base 8 ) :";
      output_label_3.innerHTML = "Hexadecimal Number ( Base 16 ) :";
      break;
    case 2:
      ////console.log("Input selected as decimal");
      input_type_label.innerHTML = "Decimal Number ( Base 10 ) :";
      output_label_1.innerHTML = "Binary Number ( Base 2) :";
      output_label_2.innerHTML = "Octal Number ( Base 8 ) :";
      output_label_3.innerHTML = "Hexadecimal Number ( Base 16 ) :";
      break;
    case 3:
      ////console.log("Input selected as octal");
      input_type_label.innerHTML = "Octal Number ( Base 8 ) :";
      output_label_1.innerHTML = "Binary Number ( Base 2) :";
      output_label_2.innerHTML = "Decimal Number ( Base 10 ) :";
      output_label_3.innerHTML = "Hexadecimal Number ( Base 16 ) :";
      break;
    case 4:
      ////console.log("Input selected as hexadecimal");
      input_type_label.innerHTML = "Hexadecimal Number ( Base 16 ) :";
      output_label_1.innerHTML = "Binary Number ( Base 2 ) :";
      output_label_2.innerHTML = "Decimal Number ( Base 10 ) :";
      output_label_3.innerHTML = "Octal Number ( Base 8 ) :";
      break;

    default:
      ////console.log("Default");
      break;
  }
});

function verifyBinary(valueStr) {
  if (valueStr == "") {
    ////console.error("Empty value passed to verifyBinary function.");
    addAlert("danger", "Input field should not be empty.", true, 5);
    input_value.classList.add("bg-alert-red");
    return false;
  } else {
    for (let index = 0; index < valueStr.length; index++) {
      // //console.log(valueStr[index]);
      if (valueStr[index] == 0 || valueStr[index] == 1) {
        // //console.log(valueStr[index])
        continue;
      } else {
        //console.error("Invalid Binary Number provided.");
        // //console.error(valueStr[index])
        return false;
      }
    }
    ////console.log("Valid Binary Number");
    return true;
  }
}

function verifyDecimal(valueStr) {
  if (valueStr == "") {
    //console.error("Empty value passed to verifyDecimal function.");
    addAlert("danger", "Input field should not be empty.", true, 5);
    input_value.classList.add("bg-alert-red");
    return false;
  } else {
    for (let index = 0; index < valueStr.length; index++) {
      if (parseInt(valueStr[index]) >= 0 && parseInt(valueStr[index]) < 10) {
        // //console.log(valueStr[index])
        continue;
      } else {
        // //console.error(valueStr[index])
        //console.error("Invalid Decimal Number provided.");
        return false;
      }
    }
    return true;
  }
}

function verifyOctal(valueStr) {
  if (valueStr == null || valueStr == "") {
    //console.error("Empty value passed to verifyOctal function.");
    addAlert("danger", "Input field should not be empty.", true, 5);
    input_value.classList.add("bg-alert-red");
    return false;
  } else {
    for (let index = 0; index < valueStr.length; index++) {
      if (parseInt(valueStr[index]) >= 0 && parseInt(valueStr[index]) < 8) {
        // //console.log(valueStr[index])
        continue;
      } else {
        // //console.error(valueStr[index])
        //console.error("Invalid Octal Number provided.");
        return false;
      }
    }
    return true;
  }
}

function verifyHexaDecimal(valueStr) {
  if (valueStr == null || valueStr == "") {
    //console.error("Empty value passed to verifyHexadecimal function.");
    addAlert("danger", "Input field should not be empty.", true, 5);
    input_value.classList.add("bg-alert-red");
    return false;
  } else {
    for (let index = 0; index < valueStr.length; index++) {
      let i = valueStr[index];
      if (
        (parseInt(i) >= 0 && parseInt(i) < 8) ||
        i == "A" ||
        i == "a" ||
        i == "B" ||
        i == "b" ||
        i == "C" ||
        i == "c" ||
        i == "D" ||
        i == "d" ||
        i == "E" ||
        i == "e" ||
        i == "F" ||
        i == "f"
      ) {
        // //console.log(i)
        continue;
      } else {
        // //console.error(valueStr[index])
        //console.error("Invalid Hexadecimal Number provided.");
        return false;
      }
    }
    return true;
  }
}

function binarytodecimal(binaryStr) {
  let decimal = 0;
  if (verifyBinary(binaryStr)) {
    for (let i = binaryStr.length - 1; i >= 0; i--) {
      // //console.log(binaryStr[i])
      decimal += parseInt(binaryStr[binaryStr.length - i - 1]) * Math.pow(2, i);
    }
    ////console.log(decimal);
    return decimal;
  }
}

function binarytooctal(binaryStr) {
  function convert(p) {
    if (p == "000") {
      return "0";
    } else if (p == "001") {
      return "1";
    } else if (p == "010") {
      return "2";
    } else if (p == "011") {
      return "3";
    } else if (p == "100") {
      return "4";
    } else if (p == "101") {
      return "5";
    } else if (p == "110") {
      return "6";
    } else if (p == "111") {
      return "7";
    }
  }

  ////console.log(binaryStr);

  if (verifyBinary(binaryStr)) {
    if (binaryStr.length % 3 == 2) {
      let temp = "0";
      binaryStr = temp.concat(binaryStr);
    } else if (binaryStr.length % 3 == 1) {
      let temp = "00";
      binaryStr = temp.concat(binaryStr);
    } else {
    }

    ////console.log(binaryStr);

    let parts = binaryStr.match(/.{1,3}/g);
    let octal = "";

    for (let i = 0; i < parts.length; i++) {
      ////console.log(convert(parts[i]));
      octal = octal.concat(convert(parts[i]));
    }
    ////console.log(octal);
    return octal;
  }
}

function binarytohexadecimal(binaryStr) {
  function convert(p) {
    if (p == "0000") {
      return "0";
    } else if (p == "0001") {
      return "1";
    } else if (p == "0010") {
      return "2";
    } else if (p == "0011") {
      return "3";
    } else if (p == "0100") {
      return "4";
    } else if (p == "0101") {
      return "5";
    } else if (p == "0110") {
      return "6";
    } else if (p == "0111") {
      return "7";
    } else if (p == "1000") {
      return "8";
    } else if (p == "1001") {
      return "9";
    } else if (p == "1010") {
      return "A";
    } else if (p == "1011") {
      return "B";
    } else if (p == "1100") {
      return "C";
    } else if (p == "1101") {
      return "D";
    } else if (p == "1110") {
      return "E";
    } else if (p == "1111") {
      return "F";
    }
  }

  ////console.log(binaryStr);

  if (verifyBinary(binaryStr)) {
    if (binaryStr.length % 4 == 3) {
      let temp = "0";
      binaryStr = temp.concat(binaryStr);
    } else if (binaryStr.length % 4 == 2) {
      let temp = "00";
      binaryStr = temp.concat(binaryStr);
    } else if (binaryStr.length % 4 == 1) {
      let temp = "000";
      binaryStr = temp.concat(binaryStr);
    } else {
    }

    ////console.log(binaryStr);

    let parts = binaryStr.match(/.{1,4}/g);
    let octal = "";

    for (let i = 0; i < parts.length; i++) {
      ////console.log(convert(parts[i]));
      octal = octal.concat(convert(parts[i]));
    }
    //console.log(octal);
    return octal;
  }
}

function decimaltobinary(decimalStr) {
  if (verifyDecimal(decimalStr)) {
    let binary = "";
    //console.log(decimalStr);
    let decimal = Number(decimalStr);
    //console.log(decimal);
    while (decimal >= 1) {
      binary = binary.concat(decimal % 2);
      decimal = Math.floor(decimal / 2);
      // //console.log(binary);
    }
    let splitBinary = binary.split("");
    let reverseArray = splitBinary.reverse();
    let joinArray = reverseArray.join("");
    //console.log(joinArray);
    return joinArray;
  }
}

function decimaltooctal(decimalStr) {
  if (verifyDecimal(decimalStr)) {
    let octal = "";
    //console.log(decimalStr);
    let decimal = Number(decimalStr);
    //console.log(decimal);
    while (decimal >= 1) {
      octal = octal.concat(decimal % 8);
      decimal = Math.floor(decimal / 8);
      // //console.log(octal);
    }
    let splitBinary = octal.split("");
    let reverseArray = splitBinary.reverse();
    let joinArray = reverseArray.join("");
    //console.log(joinArray);
    return joinArray;
  }
}

function decimaltohexadecimal(decimalStr) {
  if (verifyDecimal(decimalStr)) {
    let hexadecimal = "";

    function convert(i) {
      if (i >= 0 && i < 10) {
        return i;
      } else if (i == 10) {
        return "A";
      } else if (i == 11) {
        return "B";
      } else if (i == 12) {
        return "C";
      } else if (i == 13) {
        return "D";
      } else if (i == 14) {
        return "E";
      } else if (i == 15) {
        return "F";
      }
    }

    //console.log(decimalStr);
    let decimal = Number(decimalStr);
    //console.log(decimal);
    while (decimal > 1) {
      hexadecimal = hexadecimal.concat(convert(decimal % 16));
      decimal = Math.floor(decimal / 16);
      // //console.log(hexadecimal);
    }
    let splitBinary = hexadecimal.split("");
    let reverseArray = splitBinary.reverse();
    let joinArray = reverseArray.join("");
    //console.log(joinArray);
    return joinArray;
  }
}

function octaltobinary(octalStr) {
  if (verifyOctal(octalStr)) {
    let binary = "";
    function convert(i) {
      if (i == 0) return "000";
      else if (i == 1) return "001";
      else if (i == 2) return "010";
      else if (i == 3) return "011";
      else if (i == 4) return "100";
      else if (i == 5) return "101";
      else if (i == 6) return "110";
      else if (i == 7) return "111";
    }
    for (let i = 0; i < octalStr.length; i++) {
      binary = binary.concat(convert(octalStr[i]));
    }
    //console.log(binary);
    return binary;
  }
}

function octaltodecimal(octalStr) {
  if (verifyOctal(octalStr)) {
    let decimal = 0;
    for (let i = octalStr.length - 1; i >= 0; i--) {
      // //console.log(octalStr[i])
      decimal += octalStr[octalStr.length - 1 - i] * Math.pow(8, i);
      // //console.log(decimal);
    }
    // decimal = decimal.toString();
    //console.log(decimal);
    return decimal;
  }
}

function octaltohexadecimal(octalStr) {
  //Dependent on octaltodecimal() and decimaltohexadecimal() functions.
  if (verifyOctal(octalStr)) {
    let decimal = octaltodecimal(octalStr);
    let hexadecimal = decimaltohexadecimal(decimal);
    //console.log(hexadecimal);
    return hexadecimal;
  }
}

function hexadecimaltobinary(hexadecimalStr) {
  if (verifyHexaDecimal(hexadecimalStr)) {
    let binary = "";
    function convert(i) {
      if (i == 0) return "0000";
      else if (i == "1") return "0001";
      else if (i == "2") return "0010";
      else if (i == "3") return "0011";
      else if (i == "4") return "0100";
      else if (i == "5") return "0101";
      else if (i == "6") return "0110";
      else if (i == "7") return "0111";
      else if (i == "8") return "1000";
      else if (i == "9") return "1001";
      else if (i == "A" || i == "a") return "1010";
      else if (i == "B" || i == "b") return "1011";
      else if (i == "C" || i == "c") return "1100";
      else if (i == "D" || i == "d") return "1101";
      else if (i == "E" || i == "e") return "1110";
      else if (i == "F" || i == "f") return "1111";
    }
    for (let i = 0; i < hexadecimalStr.length; i++) {
      binary = binary.concat(convert(hexadecimalStr[i]));
    }
    //console.log(binary);
    return binary;
  }
}

function hexadecimaltodecimal(hexadecimalStr) {
  if (verifyHexaDecimal(hexadecimalStr)) {
    let decimal = 0;
    function convert(i) {
      if (i == 0) return "0";
      else if (i == "1") return 1;
      else if (i == "2") return 2;
      else if (i == "3") return 3;
      else if (i == "4") return 4;
      else if (i == "5") return 5;
      else if (i == "6") return 6;
      else if (i == "7") return 7;
      else if (i == "8") return 8;
      else if (i == "9") return 9;
      else if (i == "A" || i == "a") return 10;
      else if (i == "B" || i == "b") return 11;
      else if (i == "C" || i == "c") return 12;
      else if (i == "D" || i == "d") return 13;
      else if (i == "E" || i == "e") return 14;
      else if (i == "F" || i == "f") return 15;
    }
    for (let i = hexadecimalStr.length - 1; i >= 0; i--) {
      // //console.log(hexadecimalStr[i])
      decimal +=
        convert(hexadecimalStr[hexadecimalStr.length - 1 - i]) *
        Math.pow(16, i);
      // //console.log(decimal);
    }
    decimal = decimal.toString();
    //console.log(decimal);
    return decimal;
  }
}

function hexadecimaltooctal(hexadecimalStr) {
  if (verifyHexaDecimal(hexadecimalStr)) {
    let decimal = hexadecimaltodecimal(hexadecimalStr);
    let octal = decimaltooctal(decimal);
    //console.log(octal);
    return octal;
  }
}
