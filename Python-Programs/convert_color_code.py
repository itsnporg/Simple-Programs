"""'
A python Function That Converts RGB color code to Hex color code and vice versa
"""


def rgb_or_hex(*args):
    if len(args) == 1:
        return tuple(bytes.fromhex(args[0][1:]))
    else:
        return "#{:02x}{:02x}{:02x}".format(*args)


print(rgb_or_hex(255, 255, 255))  # rgb(255,255,255) is white
