const { SlashCommandBuilder } = require("@discordjs/builders");
const { MessageEmbed } = require("discord.js");
const fetch = require("node-fetch");

module.exports = {
  data: new SlashCommandBuilder()
    .setName("cat")
    .setDescription("Returns a cat image and a cat fact."),

  async execute(interaction) {
    await fetch("https://some-random-api.ml/animal/cat").then((res) =>
      res.json().then((json) => {
        const catEmbed = new MessageEmbed()
          .setDescription(`**Fact**\n\`\`\`${json.fact}\`\`\``)
          .setImage(json.image)
          .setColor("GREEN")
          .setAuthor("Here's a cat for you.")
          .setTimestamp()
          .setFooter(`Requested by ${interaction.user.tag}`);

        interaction.reply({ embeds: [catEmbed], ephemeral: true });
      })
    );
  },
};
