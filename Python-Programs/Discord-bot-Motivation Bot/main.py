import json
import os
import random
import string

import requests
from keep_alive import keep_alive
from nltk.sentiment.vader import SentimentIntensityAnalyzer

import discord

client = discord.Client()

starter_motivator = [
    "Cheer Up!",
    "Always remember, I am here for you!",
    "You are a great person. Remember this!",
    "Think positive man! There is always a bright side!",
    "What about you watching a funny video to swing the mood?",
]


def get_quote():
    response = requests.get("https://zenquotes.io/api/random")
    json_data = json.loads(response.text)
    quote = f"`{json_data[0]['q']}`" + "  -" + json_data[0]["a"]
    return quote


@client.event
async def on_ready():
    print("Logged in as {0.user}".format(client))


@client.event
async def on_message(message):
    if message.author == client.user:
        return

    msg = message.content.lower()

    if (
        (msg.startswith("$hello"))
        or (msg.startswith("$hi"))
        or (msg.startswith("$hey"))
    ):
        await message.channel.send(
            "Hello there! Nice to see you !!\nHow are you feeling?"
        )

    if msg.startswith("$motivate"):
        quote = get_quote()
        await message.channel.send(quote)

    if msg.startswith("$help"):
        await message.channel.send(
            "This is bot help.\nCommands:\n*` $hey, $hello, $hi `:- Bot responds.\n*` $motivate `:- Generates motivating quotes.\n*` $help `:- Bot help."
        )

    cleaned_text = msg.translate(str.maketrans("", "", string.punctuation))

    score = SentimentIntensityAnalyzer().polarity_scores(cleaned_text)
    neg = score["neg"]
    pos = score["pos"]
    if neg > pos:
        await message.channel.send(
            "I am sensing `Negative Sentiment` from you.\n"
            + f"`{random.choice(starter_motivator)}`"
        )


keep_alive()
client.run(os.environ["TOKEN"])
