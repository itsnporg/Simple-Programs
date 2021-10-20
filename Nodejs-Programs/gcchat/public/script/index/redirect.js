const hasSavedUsername = localStorage.getItem("username");

if (hasSavedUsername) redirectToRootPath();

function redirectToRootPath() {
  window.location.replace("/root");
}
