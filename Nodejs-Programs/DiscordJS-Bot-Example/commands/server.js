const { SlashCommandBuilder } = require("@discordjs/builders");
const { MessageEmbed } = require("discord.js");

module.exports = {
  data: new SlashCommandBuilder()
    .setName("server")
    .setDescription("Returns info about server."),

  async execute(interaction) {
    const serverEmbed = new MessageEmbed()
      .setColor("#00FF00")
      .setAuthor(`ServerInfo of ${interaction.guild.name}`)
      .setFooter(`Requested by ${interaction.user.tag}`)
      .setTimestamp()
      .setThumbnail(interaction.guild.iconURL({ dynamic: true }))
      .addFields(
        { name: "ID", value: `${interaction.guild.id}`, inline: true },
        {
          name: "Owner",
          value: `<@${interaction.guild.ownerId}>`,
          inline: true,
        },
        {
          name: "Member Count",
          value: `${interaction.guild.memberCount}`,
          inline: true,
        },
        {
          name: "Server Creation",
          value: `<t:${Math.floor(interaction.guild.createdTimestamp / 1000)}>`,
          inline: true,
        },
        {
          name: "Text Channels",
          value: `${
            interaction.guild.channels.cache.filter(
              (ch) => ch.type === "GUILD_TEXT"
            ).size
          }`,
          inline: true,
        },
        {
          name: "Voice Channels",
          value: `${
            interaction.guild.channels.cache.filter(
              (ch) => ch.type === "GUILD_VOICE"
            ).size
          }`,
          inline: true,
        },
        {
          name: "Premium Tier",
          value: `${interaction.guild.premiumTier.replace("_", " ") ?? "None"}`,
          inline: true,
        },
        {
          name: "Roles",
          value: `${interaction.guild.roles.cache.size}`,
          inline: true,
        },
        {
          name: "Vanity URL Code",
          value: `${interaction.guild.vanityURLCode ?? "None"}`,
          inline: true,
        }
      );
    await interaction.reply({ embeds: [serverEmbed], ephemeral: true });
  },
};
