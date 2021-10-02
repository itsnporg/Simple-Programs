const formatMessage = require("../message");
const {
  roomIsExist,
  doesAnyRoomsCreated,
  addUserToRoom,
  removeUserFromRoom,
  getUserDetails,
} = require("../roomState");

function onNewUser(socket) {
  socket.on("new-user", ({ username, roomName }) => {
    socket.join(roomName);
    if (!roomIsExist(roomName)) return;
    addUserToRoom(socket.id, username, roomName);

    emitWelcomeUser(socket, {
      username,
      roomName,
    });

    emitNewUserJoined(socket, {
      username,
      roomName,
    });
  });
}

function emitWelcomeUser(socket, { username, roomName }) {
  const data = formatMessage(`welcome ${username} to ${roomName} room`);

  socket.emit("welcome-user", data);
  return;
}

function emitNewUserJoined(socket, { username, roomName }) {
  const data = formatMessage(`${username} joined the chat`);

  socket.to(roomName).emit("new-user-joined", data);
}

// for message receive
function onNewMessage(socket) {
  socket.on("new-message", (message) => {
    const user = getUserDetails(socket.id);

    emitChatMessage(socket, {
      username: user.name,
      userJoinedRoom: user.joinedRoom,
      message: message,
    });
  });
}

function emitChatMessage(socket, { username, userJoinedRoom, message }) {
  const data = formatMessage(message, username);

  socket.to(userJoinedRoom).emit("chat-message", data);
  return;
}

function onDisconnect(socket) {
  socket.on("disconnect", () => {
    const hasRooms = doesAnyRoomsCreated();
    if (!hasRooms) return;
    const userDetails = getUserDetails(socket.id);
    if (userDetails.notFound) return;
    const removedUser = removeUserFromRoom(socket.id, userDetails.joinedRoom);

    emitUserLeft(socket, {
      user: removedUser,
      room: userDetails.joinedRoom,
    });
  });
}

function emitUserLeft(socket, { user, room }) {
  const data = formatMessage(`${user} left the chat`);

  socket.to(room).emit("user-left", data);
  return;
}

module.exports = {
  onNewUser,
  onNewMessage,
  onDisconnect,
};
