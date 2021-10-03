def starts_with_vowel(word: str) -> bool:
    return word[0].lower() in "aeiou"


def translate_word(word: str) -> str:
    if starts_with_vowel(word):
        return word + "yay"

    vowel_index = 0

    for index, letter in enumerate(word):
        if starts_with_vowel(letter):
            vowel_index = index
            break

    return word[vowel_index:] + word[:vowel_index] + "ay"


def translate_list(word_list: list[str]) -> list[str]:
    return [translate_word(word) for word in word_list]


if __name__ == "__main__":
    print(starts_with_vowel("apple"))
    print(starts_with_vowel("ball"))
    print(translate_word("hockey"))
    print(translate_list(["hello", "I", "am", "very", "exited", "to", "see", "you"]))
