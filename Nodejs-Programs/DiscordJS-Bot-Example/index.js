const fs = require("fs");
const { Client, Collection, Intents } = require("discord.js");
const { token } = require("./config.json");

const client = new Client({
  intents: [Intents.FLAGS.GUILDS, Intents.FLAGS.GUILD_PRESENCES],
});
const eventFiles = fs
  .readdirSync("./events")
  .filter((file) => file.endsWith(".js"));

client.commands = new Collection();
const commandFiles = fs
  .readdirSync("./commands")
  .filter((file) => file.endsWith(".js"));

for (const file of commandFiles) {
  const command = require(`./commands/${file}`);
  client.commands.set(command.data.name, command);
  console.log(`Loaded ${file}`);
}

for (const file of eventFiles) {
  const event = require(`./events/${file}`);
  if (event.once) {
    client.once(event.name, (...args) => event.execute(...args));
  } else {
    client.on(event.name, (...args) => event.execute(...args));
  }
  console.log(`Loaded ${file}`);
}

client.on("interactionCreate", async (interaction) => {
  if (!interaction.isCommand()) return;

  const command = client.commands.get(interaction.commandName);

  if (!command) return;

  try {
    await command.execute(interaction);
  } catch (error) {
    console.error(error);
    return interaction.reply({
      content: "There was an error while executing this command!",
      ephemeral: true,
    });
  }
});

client.login(token);
