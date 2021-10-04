const { SlashCommandBuilder } = require("@discordjs/builders");
const { MessageEmbed } = require("discord.js");
const fetch = require("node-fetch");

module.exports = {
  data: new SlashCommandBuilder()
    .setName("slap")
    .setDescription("Returns a slapping GIF")
    .addUserOption((option) =>
      option.setName("user").setDescription("Get user").setRequired(true)
    ),

  async execute(interaction) {
    const user = interaction.options.getUser("user");
    if (user === interaction.user || user.bot) {
      return await interaction.reply(
        `You cannot slap ${user.bot ? "a bot." : "yourself."}`
      );
    }
    const { image } = await fetch("http://api.nekos.fun:8080/api/slap").then(
      (res) => res.json()
    );
    const slapEmbed = new MessageEmbed()
      .setAuthor(`${interaction.user.tag} slapped ${user.tag}`)
      .setImage(image)
      .setTimestamp()
      .setColor("GREEN");

    await interaction.reply({ embeds: [slapEmbed] });
  },
};
