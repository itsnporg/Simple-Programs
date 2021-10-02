// this is just logic, no fancy loader or alert, you can impplement your own alert and loader

const cardInput = document.getElementById('card');
const validateBtn = document.getElementById('validate');

const fineInput = function (input) {
  const trimedInput = input.trim();
  const finedInput = trimedInput.replace(/\D/g, '');
  return finedInput;
};

const sumDigit = function (n) {
  let sum = 0;
  let temp = n;

  while (temp !== 0) {
    sum += temp % 10;
    temp = Math.trunc(temp / 10);
  }

  return sum;
};

const validateInput = function (rawInput) {
  const input = fineInput(rawInput);

  if (/[^0-9-\s]+/.test(rawInput)) {
    return {
      isValid: false,
      message: 'Only space, dash and digits are allowed'
    };
  }

  if (!input) {
    return {
      valid: false,
      message: 'Please enter card number'
    };
  }

  return {
    valid: true,
    message: 'Input is a number.'
  };
};

const findCardType = function (num) {
  const firstTwoDigits = +`${num}`.slice(0, 2);
  const totalDigits = +`${num}`.length;

  if (
    totalDigits === 15 &&
    (firstTwoDigits === 34 || firstTwoDigits === 37 || firstTwoDigits === 36)
  ) {
    return 'American Express';
  } else if (
    totalDigits === 16 &&
    (firstTwoDigits === 51 ||
      firstTwoDigits === 52 ||
      firstTwoDigits === 53 ||
      firstTwoDigits === 54 ||
      firstTwoDigits === 55)
  ) {
    return 'MasterCard';
  } else if (
    (totalDigits === 16 || totalDigits === 13) &&
    Math.trunc(firstTwoDigits / 10) === 4
  ) {
    return 'Visa';
  } else {
    return 'Unknown card';
  }
};

const validateChecksum = function (num) {
  const numStr = `${num}`;

  const checksum = [...numStr].reverse().reduce((acc, curr, index) => {
    if (index % 2 === 0) {
      return acc + +curr;
    } else {
      return acc + sumDigit(+curr * 2);
    }
  }, 0);

  const isValid = checksum % 10 === 0 ? true : false;
  return isValid;
};

validateBtn.addEventListener('click', function (e) {
  e.preventDefault();

  const input = cardInput.value;
  const validation = validateInput(input);

  if (validation.valid) {
    const cardType = findCardType(fineInput(input));
    const isValid = validateChecksum(fineInput(input));

    if (isValid) {
      alert(`${cardType} card is valid.`);
    } else {
      alert(`${cardType} is invalid.`);
    }
  } else {
    alert(validation.message);
  }
});
