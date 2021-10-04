#! /usr/local/bin/python

import argparse
import re
from os import getcwd, path

import requests

# script to get placeholder image from via.placeholder.com api
# by taking input from user via argparse
# https://via.placeholder.com/600x400


def main():
    parser = argparse.ArgumentParser(
        description="Get placeholder image from via.placeholder.com",
    )
    parser.add_argument("size", help="dimensions of the image.")
    parser.add_argument(
        "-bc", help="background color of image", default="cdcdcc", dest="bgcolor"
    )
    parser.add_argument(
        "-fc", help="foreground color of image", default="9g9797", dest="fgcolor"
    )
    parser.add_argument("-t", help="text to be displayed on image", dest="text")
    parser.add_argument("-e", help="extension of image", default="png", dest="ext")
    parser.add_argument("-p", help="path to save image", default=getcwd(), dest="path")
    parser.add_argument(
        "-c", help="number of images to be generated", default=1, dest="count", type=int
    )
    args = parser.parse_args()

    if not (re.fullmatch(r"^\d+x\d+$|^\d+$", args.size)):
        print("Please enter valid size")
        exit(1)

    if re.fullmatch(r"^\d+$", args.size):
        args.size = f"{args.size}x{args.size}"

    if args.text is None:
        args.text = args.size

    if not path.isdir(args.path):
        print("Path doesn't point to a directory.")
        exit(1)

    for i in range(args.count):
        url = f"https://via.placeholder.com/{args.size}.{args.ext}/{args.bgcolor}/{args.fgcolor}/?text={args.text}-{i+1}"

        r = requests.get(url)
        file_path = path.join(args.path, f"{args.text}-{i+1}.{args.ext}")
        with open(file_path, "wb") as f:
            f.write(r.content)
            print(f"Successfully downloaded to {file_path}")


if __name__ == "__main__":
    main()
