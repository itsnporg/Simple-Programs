print(
    "The given values are palindrome"
    if (a := (input("Enter something: "))) == a[::-1]
    else "The gives values aren't palindrome"
)
