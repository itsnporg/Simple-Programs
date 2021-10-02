const toggleDate = () => {
  var dateField = document.getElementById("dob");
  dateField.setAttribute("type", "date");
};

const email_db = ["shresthanishant011@gmail.com"];
const user_db = ["srestn011", "nishant", "prashant"];
var isNameValid = false;
var isEmailValid = false;
var isUsernameValid = false;
var isdobValid = false;
var isPasswordValid = false;
var isPasswordMatched = false;
// password shower
var passShow = false;
const formValidator = () => {
  if (
    isNameValid &&
    isEmailValid &&
    isUsernameValid &&
    isdobValid &&
    isPasswordValid &&
    isPasswordMatched
  ) {
    document.getElementById("submit-btn").removeAttribute("disabled");
    document.getElementById("submit-btn").setAttribute("type", "submit");
  }
};
const showPassword = () => {
  if (passShow) {
    document.getElementById("password1").type = "password";
    document.getElementById("password2").type = "password";
    document.getElementById("show_hide-icon").classList.remove("fa-eye-slash");
    document.getElementById("show_hide-icon").classList.add("fa-eye");

    passShow = false;
  } else {
    document.getElementById("password1").type = "text";
    document.getElementById("password2").type = "text";
    document.getElementById("show_hide-icon").classList.remove("fa-eye");

    document.getElementById("show_hide-icon").classList.add("fa-eye-slash");

    passShow = true;
  }
};
// validates email
const emailValidator = (email) => {
  const email_warner = document.getElementById("email-warning");
  if (email !== "") {
    if (email.match(/^\w+([\.-]?\w+)*@\w+([\.-]?\w+)*(\.\w{2,3})+$/)) {
      if (email_db.includes(email)) {
        isEmailValid = false;
        email_warner.innerHTML = "Email already registered.";
      } else {
        isEmailValid = true;
        email_warner.innerHTML = "";
      }
    } else {
      email_warner.innerHTML = "Please enter a valid email.";
    }
  } else {
    email_warner.innerHTML = "Email cannot be empty.";
  }
  formValidator();
};

const nameValidator = (name_value, len) => {
  const name_warner = document.getElementById("name-warning");
  if (!name_value.match(/[1234567890]/)) {
    if (len > 32) {
      name_warner.innerHTML =
        "Name is too long. It should be less than 32 letters.";
      isNameValid = false;
    } else if (len < 2) {
      name_warner.innerHTML = "Name should be at least of 2 letter";
      isNameValid = false;
    } else {
      name_warner.innerHTML = "";
      isNameValid = true;
    }
  } else {
    isNameValid = false;
    name_warner.innerHTML = "Name should not contain numbers.";
  }
  formValidator();
};

const usernameValidator = (username) => {
  const username_warner = document.getElementById("username-warning");
  if (username.match(/[-!$%^&*()_ +|~=`\\#{}\[\]:";'<>?,.\/]/)) {
    isUsernameValid = false;
    username_warner.innerHTML =
      "Username should be formed using letters and numbers only.";
  } else {
    if (username === "") {
      isUsernameValid = false;
      username_warner.innerHTML = "Username cannot be empty.";
    } else if (username.length > 20) {
      isUsernameValid = false;
      username_warner.innerHTML = "Username should be less than 20 character.";
    } else if (user_db.includes(username)) {
      isUsernameValid = false;

      username_warner.innerHTML = "This username is already taken.";
    } else {
      isUsernameValid = true;
      username_warner.innerHTML = "";
    }
  }
  formValidator();
};

const dobValidator = (dob) => {
  const dob_warner = document.getElementById("dob-warning");
  const age = Date.now() - Date.parse(dob);
  if (dob !== "") {
    if (age >= 567993600000) {
      isdobValid = true;
      dob_warner.innerHTML = "";
    } else {
      isdobValid = false;
      if (Date.parse(dob) > Date.now()) {
        dob_warner.innerHTML = "Date cannot be in future.";
      } else {
        dob_warner.innerHTML = "Your age needs to be above 18 first.";
      }
    }
  } else {
    isdobValid = false;
    dob_warner.innerHTML = "Date of Birth is mandatory field.";
  }
  formValidator();
};

const checkPasswordStrength = (password) => {
  const password_warner = document.getElementById("password1-warning");
  if (password !== "") {
    if (password.length <= 3) {
      isPasswordValid = false;
      password_warner.innerHTML =
        "Password should be at least of 4 characters.";
    } else {
      const common_pass_list = [
        "1234",
        "12345",
        "123456",
        "1234567",
        "12345678",
        "123456789",
        "1234567890",
        "qwerty",
        "password",
        "qwerty123",
        "1q2w",
        "1q2w3",
        "1q2w3e",
      ];
      isPasswordValid = true;
      if (common_pass_list.includes(password)) {
        password_warner.innerHTML = "Very weak. (Easily predictable password.)";
      } else {
        const full_name = document.getElementById("name").value;
        const username = document.getElementById("username").value;
        const dob = document.getElementById("dob").value;
        const dates = dob.split("-");
        const names = full_name.split(" ");
        let insecure_variables = [...names, username, ...dates];
        var uses_insecure_variables = false;

        for (var i = 0; i < insecure_variables.length; i++) {
          if (insecure_variables[i] !== "") {
            if (
              password
                .toLowerCase()
                .includes(insecure_variables[i].toLowerCase())
            ) {
              uses_insecure_variables = true;
            }
          }
          break;
        }
        if (
          password.match(/[-!$%^&*()_ +|~=`\\#{}\[\]:";'<>?,.\/1234567890 ]/)
        ) {
          if (uses_insecure_variables) {
            if (password.length < 5) {
              password_warner.innerHTML =
                "Very Weak (Contains guessable information)";
            } else if (password.length < 8) {
              password_warner.innerHTML =
                "Weak (Contains guessable information)";
            } else if (password.length <= 10) {
              password_warner.innerHTML =
                "Medium (Contains guessable information)";
            } else {
              password_warner.innerHTML =
                "Strong (Contains guessable information)";
            }
          } else {
            if (password.length < 5) {
              password_warner.innerHTML = "Weak";
            } else if (password.length < 8) {
              password_warner.innerHTML = "Medium";
            } else if (password.length <= 10) {
              password_warner.innerHTML = "Strong";
            } else {
              password_warner.innerHTML = "Very Strong";
            }
          }
        } else {
          if (uses_insecure_variables) {
            if (password.length < 5) {
              password_warner.innerHTML =
                "Very Weak (Contains guessable information)";
            } else if (password.length < 8) {
              password_warner.innerHTML =
                "Weak (Contains guessable information)";
            } else if (password.length <= 10) {
              password_warner.innerHTML =
                "Medium (Contains guessable information)";
            } else {
              password_warner.innerHTML =
                "Strong (Contains guessable information)";
            }
          } else {
            if (password.length < 5) {
              password_warner.innerHTML = "Weak";
            } else if (password.length < 8) {
              password_warner.innerHTML = "Medium";
            } else {
              password_warner.innerHTML = "Strong";
            }
          }
        }
      }
    }
  } else {
    password_warner.innerHTML = "Password cannot be empty.";
  }
  passwordConfirmer();
};
const passwordConfirmer = () => {
  const pass1 = document.getElementById("password1").value;
  const pass2 = document.getElementById("password2").value;
  if (pass2 !== "") {
    if (pass1 !== "") {
      if (pass1 === pass2) {
        isPasswordMatched = true;
        document.getElementById("password2-warning").innerHTML =
          "Ready to go!!";
      } else {
        isPasswordMatched = false;
        document.getElementById("password2-warning").innerHTML =
          "Passwords aren't matching.";
      }
    } else {
      isPasswordMatched = false;

      document.getElementById("password2-warning").innerHTML =
        "Please set your password first.";
    }
  }
  formValidator();
};
