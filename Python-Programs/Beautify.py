import os
import shutil

file_dict = {}


def prettify(folder_path):

    try:

        os.chdir(folder_path)

    except FileNotFoundError:

        print("\nInvalid folder path!!")

    else:

        for file in os.listdir():

            if os.path.isfile(file):

                file_name, file_ext = os.path.splitext(file)

                file_dict[file_name] = file_ext

        for value in file_dict.values():

            try:

                path = os.path.join(folder_path, value.strip(".").upper())

                os.mkdir(path)

            except FileExistsError:

                pass

        for key, value in file_dict.items():

            shutil.move(
                folder_path + "\\" + key + value,
                os.path.join(
                    folder_path, value.strip(".").upper() + "\\" + key + value
                ),
            )

        print("\nPrettification Successful!!")


if __name__ == "__main__":

    print("***************************************\n")

    print(
        "█▀▀ █▀█ █░░ █▀▄ █▀▀ █▀█   █▀█ █▀█ █▀▀ ▀█▀ ▀█▀ █ █▀▀ █ █▀▀ █▀█\n"
        "█▀░ █▄█ █▄▄ █▄▀ ██▄ █▀▄   █▀▀ █▀▄ ██▄ ░█░ ░█░ █ █▀░ █ ██▄ █▀▄"
    )

    print(
        "\n***************************************           - Developed by Diwash007\n"
    )

    print("Note: Close the folder window before prettifying")

    while True:

        print("\n\nEnter the path to the folder to prettify:")

        f_path = input()

        if f_path:

            prettify(f_path)

        else:

            print("\nInvalid folder path!!")
