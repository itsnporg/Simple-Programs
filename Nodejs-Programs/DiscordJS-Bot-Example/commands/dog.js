const { SlashCommandBuilder } = require("@discordjs/builders");
const { MessageEmbed } = require("discord.js");
const fetch = require("node-fetch");

module.exports = {
  data: new SlashCommandBuilder()
    .setName("dog")
    .setDescription("Returns a fact and an image of a dog."),

  async execute(interaction) {
    const { image, fact } = await fetch(
      "https://some-random-api.ml/animal/dog"
    ).then((res) => res.json());
    const dogEmbed = new MessageEmbed()
      .setDescription(`**Fact**\n\`\`\`${fact}\`\`\``)
      .setAuthor(`Here's a dog for you!`)
      .setImage(image)
      .setColor("GREEN")
      .setTimestamp()
      .setFooter(`Requested by ${interaction.user.tag}`);

    interaction.reply({ embeds: [dogEmbed], ephemeral: true });
  },
};
