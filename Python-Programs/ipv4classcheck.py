import math
import sys


def cont():
    print("Do you want to continue ")
    print("Press Y/N to continue and exit respectively")
    inputchar = input()
    if inputchar == "Y" or inputchar == "y":
        switch()
    elif inputchar == "N" or inputchar == "n":
        sys.exit()


def switch():
    print("-" * 40)
    print("1) Check Class of IPV4 Address")
    print("2) Exit")
    print("-" * 40)
    option = int(input("your option : "))
    if option == 1:
        data = input("Enter the ip address to check its class:")
        octet = data.split(".")
        (first_byte, second_byte, third_byte, fourth_byte) = (
            int(octet[0]),
            int(octet[1]),
            int(octet[2]),
            int(octet[3]),
        )
        if len(str(first_byte)) > 3:
            print("Incorrect lenght of  IP in first octet")
            cont()
        elif len(str(second_byte)) > 3:
            print("Incorrect lenght of  IP in second octet")
            cont()
        elif len(str(third_byte)) > 3:
            print("Incorrect lenght of  IP in third octet")
        elif len(str(fourth_byte)) > 3:
            print("Incorrect lenght of  IP in fourth octet")
            cont()
        elif octet[4:]:
            print("Extra bits encountered so  Give IP in Format as A.B.C.D ")
            cont()

        if first_byte == 0 or first_byte <= 127:
            if second_byte == 0 or second_byte <= 255:
                if third_byte == 0 or third_byte <= 255:
                    if fourth_byte == 0 or fourth_byte <= 255:
                        print("Class A IP")

                        cont()
                    else:
                        print("Invalid 4th octet of Class A IP")
                        cont()
                else:
                    print("Invalid 3rd octet of Class A IP")
                    cont()
            else:
                print("Invalid 2nd octet of Class A IP")
                cont()

        elif first_byte == 128 or first_byte <= 191:
            if second_byte == 0 or second_byte <= 255:
                if third_byte == 0 or third_byte <= 255:
                    if fourth_byte == 0 or fourth_byte <= 255:
                        print("Class B IP")

                        cont()
                    else:
                        print("Invalid 4th octet of Class B IP")
                        cont()
                else:
                    print("Invalid 3rd octet of Class B IP")
                    cont()
            else:
                print("Invalid 2nd octet of Class B IP")
                cont()
        elif first_byte == 192 or first_byte <= 223:
            if second_byte == 0 or second_byte <= 255:
                if third_byte == 0 or third_byte <= 255:
                    if fourth_byte == 0 or fourth_byte <= 255:
                        print("Class C IP")

                        cont()
                    else:
                        print("Invalid 4th octet of Class C IP")
                        cont()
                else:
                    print("Invalid 3rd octet of Class C IP")
                    cont()
            else:
                print("Invalid 2nd octet of Class C IP")
                cont()
        elif first_byte == 224 or first_byte <= 239:
            if second_byte == 0 or second_byte <= 255:
                if third_byte == 0 or third_byte <= 255:
                    if fourth_byte == 0 or fourth_byte <= 255:
                        print("Class D IP")

                        cont()
                    else:
                        print("Invalid 4th octet of Class D IP")
                        cont()
                else:
                    print("Invalid 3rd octet of Class D IP")
                    cont()
            else:
                print("Invalid 2nd octet of Class D IP")
                cont()
        elif first_byte == 240 or first_byte <= 255:
            if second_byte == 0 or second_byte <= 255:
                if third_byte == 0 or third_byte <= 255:
                    if fourth_byte == 0 or fourth_byte <= 255:
                        print("Class E IP")

                        cont()
                    else:
                        print("Invalid 4th octet of Class E IP")
                        cont()
                else:
                    print("Invalid 3rd octet of Class E IP")
                    cont()
            else:
                print("Invalid 2nd octet of Class E IP")
                cont()

        else:
            print("Invalid IP")
            cont()

    elif option == 2:
        print("Exit")


switch()
