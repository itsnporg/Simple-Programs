const Sequelize = require("sequelize");

const sequelize = new Sequelize("database", "user", "password", {
  host: "localhost",
  dialect: "sqlite",
  storage: "database.sqlite",
});

const Mutes = sequelize.define("mutes", {
  userID: {
    type: Sequelize.BIGINT,
    unique: true,
  },
  reason: Sequelize.STRING,
  guildID: Sequelize.BIGINT,
  roles: Sequelize.STRING,
});

module.exports = { Mutes };
