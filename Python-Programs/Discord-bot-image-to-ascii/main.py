import random
import string
import urllib.request

from dotenv import load_dotenv
from PIL import Image

import discord

load_dotenv(".env")
import os

client = discord.Client()
token = os.environ["TOKEN"]


@client.event
async def on_message(message):
    messageContent = message.content
    if messageContent.startswith("!ascii"):

        def get_random_string():
            letters = string.ascii_lowercase
            return "".join(random.choice(letters) for i in range(10))

        ASCII_CHARS = ["@", "#", "S", "%", "?", "*", "+", ";", ":", ",", "."]

        # resize image according to a new width
        def resize_image(image, new_width=100):
            width, height = image.size
            ratio = height / width
            new_height = int(new_width * ratio)
            resized_image = image.resize((new_width, new_height))
            return resized_image

        # convert each pixel to grayscale
        def grayify(image):
            grayscale_image = image.convert("L")
            return grayscale_image

        # convert pixels to a string of ascii characters
        def pixels_to_ascii(image):
            pixels = image.getdata()
            characters = "".join([ASCII_CHARS[pixel // 25] for pixel in pixels])
            return characters

        try:
            urlParam = messageContent.split(" ")[1]
            randomStroageString = get_random_string()
            imageStorageLocation = f"images/{randomStroageString}.png"
            fileStorageLocation = f"files/{randomStroageString}.txt"
            urllib.request.urlretrieve(urlParam, imageStorageLocation)
            image = Image.open(imageStorageLocation)
            new_image_data = pixels_to_ascii(grayify(resize_image(image)))

            # format
            new_width = 100
            pixel_count = len(new_image_data)
            ascii_image = "\n".join(
                [
                    new_image_data[index : (index + new_width)]
                    for index in range(0, pixel_count, new_width)
                ]
            )

            with open(fileStorageLocation, "w") as f:
                f.write(ascii_image)

            await message.channel.send(file=discord.File(fileStorageLocation))

            os.remove(imageStorageLocation)
            os.remove(fileStorageLocation)

        except Exception as e:
            print(e)
            await message.channel.send("There was an error processing your request")


client.run(token)
