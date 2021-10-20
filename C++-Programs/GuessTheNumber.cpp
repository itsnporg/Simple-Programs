#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

// Some important instructions for the game.
void importantInstructions() {
	cout << "\"Guess The Number...\""<< endl << endl;
	cout << "Please note :-" << endl;
	cout << "1.) Enter your number whenever asked." << endl;
	cout << "2.) After entering the number a proper message will be displayed to help you reach the guessing number." << endl << endl;
    cout << "Game starts..." << endl<<endl;
}

// To return the difference between guessing number and the guessed number.
int checkNumDifference(int guessingNumber, int guessedNumber) {
	return (guessingNumber-guessedNumber);
}

// To return the number to be guessed.
int generateGuessingNumber() {
	srand((unsigned)time(0));
	return ((rand()%100)+1);
}

// To return the appropriate message after comparing the guessing number and the guessed number.
string generateAppropriateMessage(int guessingNumber, int guessedNumber) {
	int difference = checkNumDifference(guessingNumber, guessedNumber);
	string message = "";
	if (difference == 0)
		message = "--- Congratulations!!! You found the number!";
	else if (abs(difference) <= 5) {
		if (difference < 0)
			message = "--- Hey! You are too close to the number. Please decrease your number.";
		else
			message = "--- Hey! You are too close to the number. Please increase your number.";
	}
	else if (abs(difference) <= 10) {
		if (difference < 0)
			message = "--- Keep trying! You are close enough to the number. Please decrease your number.";
		else
			message = "--- Keep trying! You are close enough to the number. Please increase your number.";
	}
	else {
		if (difference < 0)
			message = "--- Sorry! You are too far from the number. Please decrease your number.";
		else
			message = "--- Sorry! You are too far from the number. Please increase your number.";
	}
	return message;
}

// Game implementation starts here.
int main() {
	importantInstructions();
	int guessingNumber = generateGuessingNumber();
	while (true) {
		int guessedNumber;
		cout << "Enter a number : ";
		cin >> guessedNumber;
		cout << generateAppropriateMessage(guessingNumber, guessedNumber) << endl;
		if (guessedNumber == guessingNumber)
			break;
	}
	return 0;
}