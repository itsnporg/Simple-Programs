function getName() {
  let nameField = document.getElementById("nameField").value;
  let result = document.getElementById("result");
  var withoutSpace = nameField.replace(/ /g, "");
  var length = withoutSpace.length;

  if (nameField.length < 3) {
    result.textContent = "Your name must contain at least 3 characters";
  } else {
    result.innerHTML = "Your name is: " + nameField + "<br> Number of characters: " + length;
    console.log(length);

  }
}

let subButton = document.getElementById("subButton");
subButton.addEventListener("click", getName, false);
