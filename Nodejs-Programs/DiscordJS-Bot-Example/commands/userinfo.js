const { SlashCommandBuilder } = require("@discordjs/builders");
const { MessageEmbed } = require("discord.js");

module.exports = {
  data: new SlashCommandBuilder()
    .setName("user")
    .setDescription("Returns info about a user")
    .addUserOption((option) =>
      option
        .setName("user")
        .setDescription("User to get info")
        .setRequired(false)
    ),

  async execute(interaction) {
    const user = interaction.options.getUser("user") ?? interaction.user;
    const member = await interaction.guild.members.fetch(user.id);
    const roles = member.roles.cache
      .sort((a, b) => b.position - a.position)
      .map((r) => r)
      .slice(0, -1)
      .join(",");

    const permissions = member
      .permissionsIn(interaction.channel)
      .toArray()
      .slice(0, 8)
      .sort((a, b) => b.position - a.position)
      .map((p) =>
        p
          .split("_")
          .map((m) => `${m.charAt().toUpperCase()}${m.slice(1).toLowerCase()}`)
          .join(" ")
      )
      .join(", ");

    const userEmbed = new MessageEmbed()
      .setColor(`${member.displayHexColor}`)
      .setAuthor(`Userinfo of ${user.tag}`)
      .setFooter(`Requested by ${interaction.user.tag}`)
      .setTimestamp()
      .setThumbnail(user.avatarURL({ dynamic: true }))
      .addFields(
        { name: "ID", value: user.id, inline: true },
        {
          name: "Joined Server at",
          value: `<t:${Math.floor(member.joinedAt / 1000)}>`,
          inline: true,
        },
        {
          name: "Created at",
          value: `<t:${Math.floor(user.createdAt / 1000)}>`,
          inline: true,
        },
        {
          name: "Nickname",
          value: `${member.nickname ?? member.user.username}`,
          inline: true,
        },

        { name: "Permissions", value: permissions },
        { name: "Roles", value: roles }
      );
    await interaction.reply({ embeds: [userEmbed], ephemeral: true });
  },
};
