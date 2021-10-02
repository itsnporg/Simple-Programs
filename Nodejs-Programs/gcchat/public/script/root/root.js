const availableRoomsContainer = document.querySelector("#available-rooms");
const noRoomsMessageElement =
  availableRoomsContainer.querySelector(".no-rooms-info");

socket.on("room-created", (roomName) => {
  if (noRoomsMessageElement !== null) {
    removeNoRoomsMessage();
  }
  insertRoomDivElement(roomName);
});

function removeNoRoomsMessage() {
  availableRoomsContainer.removeChild(noRoomsMessageElement);
}

function insertRoomDivElement(roomName) {
  availableRoomsContainer.appendChild(createRoomDivContainer(roomName));
}

function createRoomDivContainer(roomName) {
  const roomDivContainer = document.createElement("div");
  roomDivContainer.classList.add("room");
  roomDivContainer.appendChild(createRoomLinkElement(roomName));

  return roomDivContainer;
}

function createRoomLinkElement(roomName) {
  const roomLinkElement = document.createElement("a");
  roomLinkElement.classList.add("room__link");
  roomLinkElement.href = `/room/${roomName}`;
  roomLinkElement.textContent = roomName;

  return roomLinkElement;
}
