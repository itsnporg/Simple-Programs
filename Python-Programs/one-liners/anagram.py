print(
    "The given strings are anagrams."
    if __import__("collections").Counter(input("Enter 1st word: "))
    == __import__("collections").Counter(input("Enter 2nd word: "))
    else "The given strings aren't anagrams."
)
