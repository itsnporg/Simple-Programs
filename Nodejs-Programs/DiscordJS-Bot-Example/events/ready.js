const { Mutes, Warns } = require("../models");
module.exports = {
  name: "ready",
  once: true,
  execute(client) {
    client.user.setPresence({
      activities: [{ name: "discord.js Pog" }],
      status: "dnd",
    });
    console.log(`Ready! Logged in as ${client.user.tag}`);
    Mutes.sync();
    Warns.sync();
    console.log("Synced Mutes");
  },
};
