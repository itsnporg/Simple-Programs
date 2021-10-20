"use strict";

const path = require("path");
const AutoLoad = require("fastify-autoload");
const fastifyStatic = require("fastify-static");

// socket client event listeners
const {
  onNewUser,
  onNewMessage,
  onDisconnect,
} = require("./utils/socket/eventHandlers");

module.exports = async function (fastify, opts) {
  fastify.register(AutoLoad, {
    dir: path.join(__dirname, "plugins"),
    options: Object.assign({}, opts),
  });

  fastify.register(require("fastify-formbody"));

  fastify.register(AutoLoad, {
    dir: path.join(__dirname, "routes"),
    options: Object.assign({}, opts),
  });

  fastify.register(fastifyStatic, {
    root: path.join(__dirname, "public"),
  });

  fastify.register(require("point-of-view"), {
    engine: {
      handlebars: require("handlebars"),
    },
    root: path.join(__dirname, "view"),
    includeViewExtension: true,
  });

  fastify.register(require("fastify-socket.io"), {});

  fastify.ready((err) => {
    if (err) throw err;

    fastify.io.on("connection", (socket) => {
      console.log("connection made");
      onNewUser(socket);
      onNewMessage(socket);
      onDisconnect(socket);
    });
  });
};
