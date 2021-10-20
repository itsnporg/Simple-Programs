/*
If you don't want to use fancy popup or loader, you can use code from logic.js instead, but make sure you remove loader from the DOM as well.
*/

const overlay = document.getElementById('loader-overlay');
const preLoader = document.getElementById('preloader');
const loader = document.getElementById('loader');
const cardInput = document.getElementById('card');
const validateBtn = document.getElementById('validate');

const showLoader = function () {
  loader.classList.remove('hidden-el');
  preLoader.classList.remove('hidden-el');
  overlay.classList.remove('hidden-el');
};

const hideLoader = function () {
  loader.classList.add('hidden-el');
  preLoader.classList.add('hidden-el');
  overlay.classList.add('hidden-el');
};

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
  showLoader();

  const input = cardInput.value;
  const validation = validateInput(input);

  if (validation.valid) {
    const cardType = findCardType(fineInput(input));
    const isValid = validateChecksum(fineInput(input));

    if (isValid) {
      Qual.success(`${cardType} card is valid.`, '');
      hideLoader();
    } else {
      if (cardType === 'Unknown card') {
        Qual.error(`Card number is invalid.`);
      } else {
        Qual.error(`${cardType} is invalid.`);
      }
      hideLoader();
    }
  } else {
    Qual.error(validation.message, '');
    hideLoader();
  }
});

document.addEventListener('DOMContentLoaded', hideLoader);
