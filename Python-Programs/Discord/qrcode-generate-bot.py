# The error parameter sets the error correction level of the code.
# Each level has an associated name given by a letter: L, M, Q, or H;
# each level can correct up to 7, 15, 25, or 30 percent of the data respectively
# Versions are any integer between 1 and 40. Where version 1 is the smallest QR code, and version 40 is the largest.

import pyqrcode

import discord
from discord.ext import commands

client = commands.Bot(command_prefix="?", help_command=None)


@client.event
async def on_ready():
    print("ok")


@client.command()
async def barcode(context, *, message):
    qr = pyqrcode.create(message, error="L", version=4, mode="binary")
    qr.png("image.png", scale=10)
    # await context.author.send(file=discord.File('image.png')) # dm
    await context.send(file=discord.File("image.png"))


client.run(token)
