import difflib

import discord
from discord.ext import commands
from discord.ext.commands import CommandNotFound

intents = discord.Intents.all()
client = commands.Bot(command_prefix="+", intents=intents, help_command=None)


@client.event
async def on_ready():
    print("Bot Online")


@client.event
async def on_command_error(ctx: commands.Context, exc):
    if isinstance(exc, CommandNotFound):
        await send_command_suggestion(ctx, ctx.invoked_with)
    else:
        pass


async def send_command_suggestion(ctx: commands.Context, command_name: str) -> None:
    """Sends user similar commands if any can be found."""
    raw_commands = []
    for cmd in client.walk_commands():
        if not cmd.hidden:
            raw_commands += (cmd.name, *cmd.aliases)
    if similar_command_data := difflib.get_close_matches(command_name, raw_commands, 1):
        similar_command_name = similar_command_data[0]
        similar_command = client.get_command(similar_command_name)

        if not similar_command:
            return
        try:
            if not await similar_command.can_run(ctx):
                return
        except commands.errors.CommandError:
            return

        misspelled_content = ctx.message.content
        e = discord.Embed()
        e.set_author(name="Did you mean:")
        e.description = misspelled_content.replace(
            command_name, similar_command_name, 1
        )
        await ctx.send(embed=e, delete_after=10.0)


client.run("TOKEN")
