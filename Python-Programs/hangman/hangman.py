import random

words_dict = {
    'laptop':'an electronic device',
    'python':'a programming language',
    'elephant':'an animal with trunk',
    'cash':'type of financial incentive',
    'hacktober':'an opensource celebration',
    'football':'a famous sport',
    'programmer':'one who codes',
}

secret_word = random.choice(list(words_dict.keys()))

guess_word = []

word_length = len(secret_word)

letter_storage = []

validators = 'qwertyuiopasdfghjklzxcvbnm'

def introduce():
    for char in secret_word:
        guess_word.append('-')
    print('your word has {} characters'.format(word_length))
    print('hint:{}'.format(words_dict[secret_word]))
    print(guess_word)

def Guess():
    count = 0
    MAX = 7
    while count < MAX:
        guess = str(input('enter letter:')).lower()
        if guess in validators:
            if guess in letter_storage:
                print('already guessed')
            else:
                letter_storage.append(guess)

            if guess in secret_word:
                for i in range(0, word_length):
                    if secret_word[i] == guess:
                        guess_word[i] = guess
                print(guess_word)
            else:
                print('sorry no letter {} in word'.format(guess))
                count = count+1
                print('{}/7 try.'.format(count))
                Hangman(count)
        else:
            print('enter alphabets only')
        if '-' not in guess_word:
            print('you won')
            input('')
            break

        if count == 7:
            print('you lost.\nthe secret word was \'{}\''.format(secret_word))
            input('')
            

def Hangman(count):
    figures = [
        """
 ------
 |    |
 |
 |
 |
 |
 |
 |
 |
----------
""",
"""
 ------
 |    |
 |    O
 |
 |
 |
 |
 |
 |
----------
""",

 """
 ------
 |    |
 |    O
 |   -+-
 | 
 |   
 |   
 |   
 |   
----------
""",
"""
 ------
 |    |
 |    O
 |  /-+-
 |   
 |   
 |   
 |   
 |   
----------
""",
"""
 ------
 |    |
 |    O
 |  /-+-/
 |   
 |   
 |   
 |   
 |   
----------
""",
"""
 ------
 |    |
 |    O
 |  /-+-/
 |    |
 |   
 |   
 |   
 |   
----------
""",

"""
 ------
 |    |
 |    O
 |  /-+-/
 |    |
 |    |
 |   | 
 |   | 
 |   
----------
""",
"""
 ------
 |    |
 |    O
 |  /-+-/
 |    |
 |    |
 |   | |
 |   | |
 |  
----------
"""
    ]

    try:
        print(figures[count])
    except IndexError:
        print('Game over')
        input('')


if __name__ == "__main__":
    introduce()
    Guess()




