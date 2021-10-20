const { SlashCommandBuilder } = require("@discordjs/builders");
const { MessageEmbed, Permissions } = require("discord.js");
const { Mutes } = require("../models");

module.exports = {
  data: new SlashCommandBuilder()
    .setName("unmute")
    .setDescription("Unmutes a user")
    .addUserOption((option) =>
      option.setName("user").setDescription("Get user").setRequired(true)
    )
    .addStringOption((option) =>
      option.setName("reason").setDescription("Get a reason").setRequired(true)
    ),

  async execute(interaction) {
    const user = interaction.options.getUser("user");
    const member = await interaction.guild.members.fetch(user.id);
    if (user === interaction.user || user.bot) {
      return await interaction.reply(
        `You cannot mute ${user.bot ? "a bot" : "yourself."}`
      );
    }
    if (!interaction.member.permissions.has(Permissions.FLAGS.MANAGE_ROLES)) {
      return await interaction.reply(
        "You don't have the required permissions to run this command."
      );
    }
    if (
      interaction.member.roles.highest.comparePositionTo(
        member.roles.highest
      ) <= 0
    ) {
      return await interaction.reply(
        "Cannot use moderation actions on users on same rank or higher than you."
      );
    }
    const mute = await Mutes.findOne({ where: { userID: user.id } });
    const roleStr = mute.roles;
    const rolesID = roleStr.toString().split(",");

    const roles = rolesID.map((role) =>
      interaction.guild.roles.cache.get(role)
    );
    await Mutes.destroy({ where: { userID: user.id } });

    await member.roles.set(roles);
    await interaction.reply(`Unmuted ${user.tag}`);
  },
};
