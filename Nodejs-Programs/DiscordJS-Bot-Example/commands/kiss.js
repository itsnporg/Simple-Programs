const { SlashCommandBuilder } = require("@discordjs/builders");
const { MessageEmbed } = require("discord.js");
const fetch = require("node-fetch");

module.exports = {
  data: new SlashCommandBuilder()
    .setName("kiss")
    .setDescription("Returns a kissing GiF")
    .addUserOption((option) =>
      option.setName("user").setDescription("Get user.").setRequired(true)
    ),

  async execute(interaction) {
    const user = interaction.options.getUser("user");
    if (user === interaction.user || user.bot) {
      await interaction.reply(
        `You cannot kiss ${user.bot ? "a bot" : "yourself."}!`
      );
      return;
    }
    const { image } = await fetch("http://api.nekos.fun:8080/api/kiss").then(
      (res) => res.json()
    );
    const kissEmbed = new MessageEmbed()
      .setAuthor(`${interaction.user.tag} kissed ${user.tag}.`)
      .setImage(image)
      .setTimestamp()
      .setColor("GREEN");

    await interaction.reply({ embeds: [kissEmbed] });
  },
};
