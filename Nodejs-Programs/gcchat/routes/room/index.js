"use strict";

const { createRoom, roomIsExist } = require("../../utils/roomState");

module.exports = async function (fastify, opts) {
  fastify.post("/", async function (request, reply) {
    const { roomName } = request.body;

    if (roomIsExist(roomName)) {
      return reply.redirect("/create_room");
    }
    createRoom(roomName);
    fastify.io.emit("room-created", roomName);
    return reply.redirect(`/room/${roomName}`);
  });

  fastify.get("/:roomName", async function (request, reply) {
    const { roomName } = request.params;

    if (!roomIsExist(roomName)) {
      return reply.redirect("/");
    }

    return reply.view("chat_room", {
      roomName: roomName,
    });
  });
};
