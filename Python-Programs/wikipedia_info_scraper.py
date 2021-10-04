import wikipedia
import cgi
def main_function():
    query = input('Write the title of the information you want to know = ')
    info = wikipedia.summary(query, 2)
    print(info)
    print()
    answer = input("Want to get more information?(Y/N)")
    if answer == "y" or answer == "Y":
        info = wikipedia.summary(query)
        print(info)
        print()
        print("SOURCE: WIKIPEDIA")
        print()
    elif answer == "n" or answer == "N":
        print("Thanks For using us. Bye Bye.....")
    else:
        print("Invalid choice")

while True:
    main_function()
