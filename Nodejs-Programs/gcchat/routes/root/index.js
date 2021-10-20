"use strict";

const { getAllActiveRooms } = require("../../utils/roomState");

module.exports = async function (fastify, opts) {
  fastify.get("/", async function (request, reply) {
    return reply.view("root", { rooms: getAllActiveRooms() });
  });
};
