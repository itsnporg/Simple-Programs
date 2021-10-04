export const validateFullName = (fullName) => {
  const fullNameValidation = /^[a-zA-Z]{2,}(?: [a-zA-Z]+){0,2}$/;
  return fullNameValidation.test(fullName);
};

export const validateEmail = (email) => {
  const emailValidator =
    /^(([^<>()[\]\\.,;:\s@"]+(\.[^<>()[\]\\.,;:\s@"]+)*)|(".+"))@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\])|(([a-zA-Z\-0-9]+\.)+[a-zA-Z]{2,}))$/;
  return emailValidator.test(email.toLowerCase());
};

export const validateAddress = (address) => {
  const addressValidator = /^([a-zA-z0-9/\\''(),-\s]{2,255})$/;
  return addressValidator.test(address);
};

export const validatePassword = (password) => {
  const passwordValidator =
    /^(?=.*[A-Za-z])(?=.*\d)(.*[#$@!%&*?]?)[A-Za-z\d#$@!%&*?]{8,}$/;
  // eslint-disable-next-line
  const passwordValidator2 =
    /^(((?=.*[a-z])(?=.*[A-Z]))|((?=.*[a-z])(?=.*[0-9]))|((?=.*[A-Z])(?=.*[0-9])))(?=.{6,})/; // 1 special character also
  return passwordValidator.test(password);
};

export const validateCardNumber = (cardNumber) => {
  const cardValidator =
    /^(?:4[0-9]{12}(?:[0-9]{3})?|[25][1-7][0-9]{14}|6(?:011|5[0-9][0-9])[0-9]{12}|3[47][0-9]{13}|3(?:0[0-5]|[68][0-9])[0-9]{11}|(?:2131|1800|35\d{3})\d{11})$/;
  return cardValidator.test(cardNumber);
};

export const validateCVC = (cvc) => {
  const cvcValidator = /^[0-9]{3}$/;
  return cvcValidator.test(cvc);
};
