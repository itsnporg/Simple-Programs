import os

import lightbulb
from dotenv import load_dotenv

load_dotenv()

bot = lightbulb.Bot(token=os.environ.get("BOT_TOKEN"), prefix=">")


@bot.command() # You can specify name as kwarg here but if you leave it empty your command name will be same as your function name
async def ping(ctx: lightbulb.Context) -> None:
    await ctx.respond(f"Pong!: {bot.heartbeat_latency * 1_000:.0f}ms") # This sends bot's ping to the Discord API in chat whenever you run the command `>ping`

@bot.command(name="avatar")
async def avatar_command(ctx: lightbulb.Context, member: hikari.Member) -> None:
    avatar_url = member.avatar_url # This is how you get a member's avatar URL
    embed = hikari.Embed( # initializing an embed
        title = f"Avatar of {member}"
        color=0x00ff00,
        timestamp = ctx.timestamp() # The time at which the context was created
    )
    embed.set_image(avatar_url)
    await ctx.respond(embed=embed) # Sending the embed to the user's channel.


if __name__ == "__main__":
    bot.run()
    
