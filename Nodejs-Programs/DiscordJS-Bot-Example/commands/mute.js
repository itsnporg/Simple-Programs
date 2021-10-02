const { SlashCommandBuilder } = require("@discordjs/builders");
const { MessageEmbed, Permissions } = require("discord.js");
const { Mutes } = require("../models");

module.exports = {
  data: new SlashCommandBuilder()
    .setName("mute")
    .setDescription("Mutes the user mentioned.")
    .addUserOption((option) =>
      option.setName("user").setDescription("Get user.").setRequired(true)
    )
    .addStringOption((option) =>
      option.setName("reason").setDescription("Get reason").setRequired(true)
    ),

  async execute(interaction) {
    const user = interaction.options.getUser("user");
    const member = await interaction.guild.members.fetch(user.id);
    const roles = member.roles.cache
      .sort((a, b) => b.position - a.position)
      .map((r) => r.id)
      .slice(0, -1)
      .join(",");
    if (user === interaction.user || user.bot) {
      return await interaction.reply(
        `You cannot mute ${user.bot ? "a bot" : "yourself."}`
      );
    }
    if (
      !interaction.member.permissions.has(Permissions.FLAGS.MANAGE_MESSAGES)
    ) {
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
    try {
      const mute = await Mutes.create({
        userID: user.id,
        reason: interaction.options.getString("reason"),
        guildID: interaction.guild.id,
        roles: roles,
      });
    } catch (error) {
      if (error.name === "SequelizeUniqueConstraintError") {
        return interaction.reply("That mute already exists.");
      }
      return interaction.reply("Something went wrong with muting this user.");
    }
    mutedRole = interaction.guild.roles.cache.find((r) => r.name === "Muted");
    await member.roles.set([mutedRole]);
    await interaction.reply(`Muted ${user.tag}`);
  },
};
