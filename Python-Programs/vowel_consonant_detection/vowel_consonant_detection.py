# This code is used to find consonant and fowel in a string

string = input("Please insert a string : ").lower()

vowel_counts = {}
consonant_counts = {}

# Define vowels and consonants
vowels = ["a", "e", "i", "o", "u"]
consonants = [
    "b",
    "c",
    "d",
    "f",
    "g",
    "h",
    "j",
    "k",
    "l",
    "m",
    "n",
    "p",
    "q",
    "r",
    "s",
    "t",
    "v",
    "w",
    "y",
    "z",
]

for word in string:
    if word in vowels:
        count = string.count(word)
        vowel_counts[word] = count
    elif word in consonants:
        count = string.count(word)
        consonant_counts[word] = count

print(f"\nVowel Count : {vowel_counts}")
print(f"Consonant Count : {consonant_counts}")
