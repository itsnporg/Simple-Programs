#include <stdio.h>
#include <stdlib.h>

/** Defining constants. YES would mean 'true' or 1 and NO would mean 'false' or 0
* There's no need to import 'bool.h' file by doing this.
*/
#define YES 1
#define NO 0

// Declaring functions
int sumOfIndividualDigits();
void isVowel(char character);
void fibonacciSeries(int numOfSeries);
void patterns();

int main() {
    int userPref, numOfSeries = 0, continuity = NO;
    char character;

    // showOptions:
    // Main menu of the program
    printf("Press '1' to print sum of individual digit of a number \n");
    printf("Press '2' to print ASCII value of a character \n");
    printf("Press '3' to print whether a character is vowel or consonant \n");
    printf("Press '4' to print fibonacci series \n");
    printf("Press '5' to see some patterns \n");
    printf("Press '6' to exit the program \n");

    scanf("%d", &userPref);

    switch (userPref) {
    case 1:
        printf("Sum of individual digits is: %d", sumOfIndividualDigits());
        break;

    case 2:
        printf("Enter a character...");
        scanf(" %c", &character);
        /**
         Example, if the user gives an alphabet 'A', the output would be 65 which is ASCII representation
         of 'A' in ASCII
        */
        printf("The ASCII value of given input is %d", character);
        break;

    case 3:
        printf("Enter an alphabetic character...");
        scanf(" %c", &character);
        isVowel(character);
        break;

    case 4:
        printf("Enter first how many fibonacci numbers you would like to see... ");
        scanf("%d", &numOfSeries);
        fibonacciSeries(numOfSeries);
        break;

    case 5:
        patterns();
        break;
   
    case 6:
        printf("\nExiting program...");
        exit(0);
        break;

    default:
        printf("The given input is invalid!!! \n");
        break;
    }


    printf("\n\nWould you like to continue?(1/0)...\n"); // 1 = Yes and 0 = true
    scanf("%d", &continuity);

    /* Checks if user wants to continue using the program or not */
    if (continuity) {
        system("cls");
        main();
    } else {
        printf("Thank you for using this application. Have a Good Day!!");
    }
    return 0;
}

/* To print the sum of individual digits of an input number*/

/**
 Example: if a user gives an input number 123, the program will give the output 6 as, 1+2+3 = 6  
 */

int sumOfIndividualDigits() {
    int sum = 0, number = 0;
    printf("Enter a number... ");
    scanf("%d", &number);

    while (number != 0) {
        sum += (number % 10);
        number /= 10;
    }
    return sum;
}

/*Checking Vowel*/

/**
 * A flaw in this program is it will display all symbols and numbers as consonants.
 * Since it would be tougher to understand the mechanism of distincting them at the moment, I didn't programme it to filter those.
*/
void isVowel(char character) {
    int isVowel = NO;
    char vowels[10] = {'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'}; //This is an example of an array.

    if (character != ' ') {
        for (int i = 0; i < 10; i++) {
            if (vowels[i] == character) {
                isVowel = YES;
                break;
            }
        }

        if (isVowel)
            printf("%c is a vowel", character);
        else
            printf("%c is a consonant", character);

    } else {
        printf("Spaces and other characters are not allowed!!");
    }
}

/*Fibonacci Series*/
void fibonacciSeries(int numOfSeries) {

    int x = 0, y = 1, z = 0, count = 0;

    while (count != numOfSeries) { //for loop could have been used here but to include all loops and also show '++' increment I used while loop
        printf("%d ", x);
        z = x + y;
        x = y;
        y = z;
        count++;
    }
}

/**
* Some patterns 
* This will help in understanding nested loop and logic behind these patten
* In the first loop, 'i' part determines the number of rows while the 'j' part determines the
* number of column
*/

void patterns() {

int i, j;
    /* This part will print a right angled triangle of '*' in ascending order i.e. */

/*
    *
    **
    ***
    ****
    *****
 */

    for (i = 0; i < 5; i++) {
        for (j = 0; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }

    printf("\n\n");

    /* This part will print a right angled triangle of '*' in descending order i.e. */

/*
    *****
    ****
    ***
    **
    *
*/

    for (i = 5; i > 0; i--) {
        for (j = 0; j < i; j++) {
            printf("*");
        }
        printf("\n");
    }

    printf("\n\n");
/*
    ABCDEEDCBA
    ABCD  DCBA
    ABC    CBA
    AB      BA
    A        A
*/

    for(i=0; i<5; i++){
        for(j = 65; j<=69-i; j++){
            printf("%c", j);
        }
        for(j = 0; j<(i*2); j++){
            printf(" ");
        }
        for(j = (69-i); j>=65; j--){
            printf("%c", j);
        }
        printf("\n");
    }

}
