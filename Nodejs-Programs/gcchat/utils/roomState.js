let activeRooms = {};

function createRoom(roomName) {
  activeRooms[roomName] = { users: {} };
  return;
}

function deleteRoom(roomName) {
  if (!roomIsExist(roomName)) return notFoundError("room does not exist");

  // if room found
  const { [roomName]: deletedRoom, ...restRooms } = activeRooms;

  activeRooms = restRooms;
  return deletedRoom;
}

function getAllActiveRooms() {
  return Object.entries(activeRooms).reduce((rooms, [roomName, ...rest]) => {
    rooms.push(roomName);
    return rooms;
  }, []);
}

function roomIsExist(roomName) {
  if (!doesAnyRoomsCreated()) return false;
  if (!activeRooms[roomName]) return false;
  return true;
}

function doesAnyRoomsCreated() {
  if (Object.keys(activeRooms).length === 0) {
    return false;
  }
  return true;
}

function addUserToRoom(id, username, roomName) {
  activeRooms[roomName].users[id] = username;
  return;
}

function removeUserFromRoom(userID, roomName) {
  if (!activeRooms[roomName].users[userID]) {
    return notFoundError("no user found");
  }

  // if user was joined
  const { [userID]: removedUser, ...restUsers } = activeRooms[roomName].users;

  activeRooms[roomName].users = restUsers;
  return removedUser;
}

function getUserJoinedRooms(id) {
  const reducer = (joinedRooms, [roomName, roomData]) => {
    if (roomData.users[id]) joinedRooms.push(roomName);
    return joinedRooms;
  };

  const initalValue = [];

  return Object.entries(activeRooms).reduce(reducer, initalValue);
}

function getUserDetails(id) {
  return Object.entries(activeRooms).reduce(
    (userDetails, [roomName, roomData]) => {
      if (roomData.users[id]) {
        userDetails = {
          name: roomData.users[id],
          joinedRoom: roomName,
        };
        return userDetails;
      }

      userDetails = notFoundError("user not joined yet");
      return userDetails;
    },
    {}
  );
}

function notFoundError(message) {
  return { notFound: message };
}

module.exports = {
  createRoom,
  deleteRoom,
  getAllActiveRooms,
  roomIsExist,
  doesAnyRoomsCreated,
  addUserToRoom,
  removeUserFromRoom,
  getUserJoinedRooms,
  getUserDetails,
};
