#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

/**Functions will be defined here*/
void welcome();
void backToMenu();
int playerChoice();
void gameManual();
void showCredits();
void startGame();

/**global variables will be defined here*/

/**
* choice = player's menu selection.
* attempts = max number of guesses player can make.
* lengthOfWord = length of word selected ranfomly. to be used to check if char guessed by player is correct or not.
* correctGuesses = It notes number of correct guesses made by player.
* indexing = for 'for loop'.
* correctBefore = to check if the word entered is correct was already entered before by the player.
*/
int choice, attempts = 6, lengthOfWord = 0, correctGuesses = 0, indexing = 0, correctBefore;

/**
* for noting which index character has been guessed correct. 0s will be changed to 1s, if the guess is correct.
*/
int letterGuessed[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

/**
* Replace the _ by the valid entered character.
*/
char answer[][1] = {"_", "_", "_", "_", "_", "_", "_", "_", "_", "_"};

/**
* guesswords contains list of words that player has to guess.
* hint contains hint for each aforementioned word that will be presented to player.
*/
char guessWords[][10] = {"apple", "linux", "orange", "football", "honey", "hockey", "elephant", "camel"};

char hint[][100] = {"A red or green juicy fruit with crispy flesh.",
                    "An open source OS built on UNIX.",
                    "The common name of a color and the fruit.",
                    "A round object that is used in playing in fields.",
                    "A sweet, sticky yellowish-brown fluid.",
                    "A game played with a hooked stick and a ball.",
                    "A huge land animal with a trunk",
                    "A desert animal"
                   };

char guessedAlpha;

int main() {
	system("cls");
	welcome();

	choice = playerChoice();
	switch (choice) {
		case 1:
			startGame();
			break;
		case 2:
			system("cls");
			gameManual();
			break;
		case 3:
			system("cls");
			showCredits();
			break;
		case 4:
			system("cls");
			printf("\n\n\n\n\n\n\n\t\t\t\t****Thank you for participating****\n\n\n\n\n");
			exit(0);
			break;
		default:
			printf("\n\n\nt\t\t\t\tThe input was invalid!!!!");
			backToMenu();
	}

	return 0;
}

/**Methods will be written here*/

//Displays Welcome Message
void welcome() {
	printf("\t\t\t\t*************************************************\n");
	printf("\t\t\t\t*\t\tWelcome to Hangman\t\t*\t\t\t");
	printf("\n\t\t\t\t*************************************************\n");
}

//When it is called, it pauses the screen until any key is pressed by the player. It redirects player to main menu.
void backToMenu() {
	printf("\n\n\t\t\t\tPress any key to continue");
	getch();
	main();
}

//Lets player choose from menu
int playerChoice() {
	printf("\n\n\t\t\t\t1. Start Game");
	printf("\t\t\t2. Show game manual");
	printf("\n\n\t\t\t\t3. Credits");
	printf("\t\t\t4. Exit");

	printf("\n\n\n\t\t\t\tEnter your choice(1-4):");
	scanf("%d", &choice);

	return choice;
}

//Displays game manual to the player
void gameManual() {
	welcome();
	printf("\n\n\n\t\t\t\t\t\tGAME MANUAL:");
	printf("\n\n\t\t\t1. You'll have 6 attempts to guess the answer correct.");
	printf("\n\n\t\t\t2. Hint will be provided on what the correct word is based on which\n\t\t\tyou'll need to guess the answer.");
	printf("\n\n\t\t\t3. Each time you'll be allowed to enter only one alphabet.'");
	printf("\n\n\t\t\t4. Entering any character other than alphabets would cost you an\n\t\t\tattempt and will also not be taken as valid entry.");
	printf("\n\n\t\t\t5. Guessing correct alphabet will not cost any attempt.");
	printf("\n\n\t\t\t6. case of the alphabets doesn't matter");

	backToMenu();
	printf("\n\n\n");
}

//Shows credits
void showCredits() {
	welcome();
	printf("\n\n\t\t\t\t\tDeveloped By: Aashish Katwal");
	printf("\n\n\t\t\t\t\tLanguage Used: C\n\n");
	backToMenu();
}

//The main game logic is conducted from this function.
void startGame() {

	srand(time(NULL)); //prevents from generating same seed. Without this, same randNumbers will be generated each time.

	int randNumIndex = rand() % 8;					 //modulo 8 because it would give a result of 0-7.
	lengthOfWord = strlen(guessWords[randNumIndex]); //length of the word to be guessed. To be used in for loop later in game logic

	//game loop
	while (correctGuesses <= lengthOfWord) {
		system("cls");
		welcome();

		printf("\n\n\n\t\t\t\tAttempts Left: %d", attempts);		   //Shows number of remaining attempts.
		printf("\n\n\t\t\t\tHint: %s", hint[randNumIndex]);			   //Shows hint on what the word is.
		printf("\n\n\n\t\t\t\tGuessed Letters: %d", correctGuesses);   //Shows how many letters have been guessed correct.
		printf("\t\tGuesses Left: %d", lengthOfWord - correctGuesses); //Shows how many letters are to be guessed now.
		printf("\n\n\n\t\t\t\t\t\t");
		for (indexing = 0; indexing < lengthOfWord; indexing++) {
			if (letterGuessed[indexing] == 1) {
				printf("%c ", guessWords[randNumIndex][indexing]);
			} else {
				printf("_ ");
			}
		}

		if (correctGuesses < lengthOfWord) {
			printf("\n\n\n\t\t\t\tEnter your guess: "); //Takes the guess alphabet from player as input.
			scanf("%*c %c", &guessedAlpha);

			/*Main logic behind game*/

			if (isalpha(guessedAlpha)) {
				//Checks if the input given by player is alphabet or not.
				correctBefore = correctGuesses;
				for (indexing = 0; indexing < lengthOfWord; indexing++) {

					if (letterGuessed[indexing] == 1) {
						//prevents player from entering same correct guess and winning the game.
						continue;
					}

					/* Checks if the letter entered by the player is a correct guess in the randomly selected word */
					if (guessedAlpha == guessWords[randNumIndex][indexing]) {
						//changes the respective index to 1 so that we can differentiate between which letters are already guessed.
						letterGuessed[indexing] = 1;
						correctGuesses++;
					}
				}
			} else {
				attempts--;
			}
		} else {
			break;
		}

		/* Below code checks if any correct word was entered. If YES, the correctGuess would be greater than zero. */
		if (correctBefore == correctGuesses) {
			attempts--;
		}
		if (attempts == 0) {
			break;
		}
	}

	if (attempts == 0) {
		printf("\n\n\t\t\t\t*** Sorry You Lost. The correct word was: %s ***\n\n\n\n", guessWords[randNumIndex]);
	} else if (correctGuesses == lengthOfWord) {
		printf("\n\n\t\t\t\t\t***  Hurray!! You Won.  ***");
	}

	printf("\n\n\t\t\t\tPress any key to continue...");
	getch();
}