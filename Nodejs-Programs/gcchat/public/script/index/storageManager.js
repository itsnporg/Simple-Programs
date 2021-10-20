const publicUsernameElement = document.querySelector("#public-username");
const usernameSaveBtnElement = document.querySelector("#username-save-btn");

usernameSaveBtnElement.addEventListener("click", clickHandler);

function clickHandler(event) {
  if (!publicUsernameElement.value) {
    alert("username is required");
    return;
  }

  if (publicUsernameElement.value.length < 5) {
    alert("atleast 5 characters is required");
    return;
  }

  saveUsername(publicUsernameElement.value);
  redirectToRootPath();
}

function saveUsername(username) {
  localStorage.setItem("username", username);
  return;
}
