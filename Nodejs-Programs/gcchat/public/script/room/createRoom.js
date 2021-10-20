const createRoomFormElement = document.querySelector("#create-room-form");
const roomNameElement = document.querySelector("#room-name");

createRoomFormElement.addEventListener("submit", formSubmitHandler);

function formSubmitHandler(event) {
  if (!roomNameElement.value) {
    event.preventDefault();
    alert("room name is required");
    return;
  }

  if (roomNameElement.value < 5) {
    event.preventDefault();
    alert("room name should be at least 5 characters long");
    return;
  }
}
