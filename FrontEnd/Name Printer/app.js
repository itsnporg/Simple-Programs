function getName() {
  let nameField = document.getElementById("nameField").value;
  let result = document.getElementById("result");

  if (nameField.length < 3) {
    result.textContent = "Your name must contain at least 3 characters";
  } else {
    result.textContent = "Your name is: " + nameField;
  }
}

let subButton = document.getElementById("subButton");
subButton.addEventListener("click", getName, false);
