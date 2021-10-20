const { SlashCommandBuilder } = require("@discordjs/builders");
const { MessageEmbed } = require("discord.js");
const fetch = require("node-fetch");

module.exports = {
  data: new SlashCommandBuilder()
    .setName("sus")
    .setDescription("Returns sus stuff, Not for kids."),

  async execute(interaction) {
    if (!interaction.channel.nsfw) {
      const embed = new MessageEmbed()
        .setAuthor("Not an NSFW Channel")
        .setDescription("I can run this command only in NSFW Channels.")
        .setImage(
          "https://images-ext-2.discordapp.net/external/hiWbEzhiEXfFaza5khoxg3mR3OWeugZwWo8vGxK8LzA/https/i.imgur.com/oe4iK5i.gif"
        )
        .setColor("RED");
      return await interaction.reply({ embeds: [embed] });
    }
    const { image } = await fetch("http://api.nekos.fun:8080/api/boobs").then(
      (res) => res.json()
    );
    const susEmbed = new MessageEmbed()
      .setAuthor(`Here's some sus stuff for you`)
      .setDescription("<:IT_heheboii:867385740189892659>")
      .setImage(image)
      .setColor("GREEN")
      .setTimestamp();

    await interaction.reply({ embeds: [susEmbed], ephemeral: true });
  },
};
