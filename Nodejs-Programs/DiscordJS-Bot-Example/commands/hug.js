const { SlashCommandBuilder } = require("@discordjs/builders");
const { MessageEmbed } = require("discord.js");
const fetch = require("node-fetch");

module.exports = {
  data: new SlashCommandBuilder()
    .setName("hug")
    .setDescription("Returns a hugging GiF.")
    .addUserOption((option) =>
      option.setName("user").setDescription("Get user").setRequired(true)
    ),

  async execute(interaction) {
    const user = interaction.options.getUser("user");
    const { image } = await fetch("http://api.nekos.fun:8080/api/hug").then(
      (res) => res.json()
    );
    if (user === interaction.user || user.bot) {
      await interaction.reply(
        `You cannot hug ${user.bot ? "a bot" : "yourself."}!`
      );
      return;
    }
    const hugEmbed = new MessageEmbed()
      .setAuthor(`${interaction.user.tag} hugged ${user.tag}.`)
      .setImage(image)
      .setColor("GREEN")
      .setTimestamp();

    await interaction.reply({ embeds: [hugEmbed] });
  },
};
