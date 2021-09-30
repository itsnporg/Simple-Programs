/******************************************************************************************************
*   Program name: armstrong.c,
*   Author name: NiyojOli(BCT029),
*   Created Path: /home/dell/Desktop/programming/armstrong.c,
*   Created Date: 05 Jul 2021, 18:31:10 (DD MON YYYY, HH:MM:SS),
*   Description: This  program checks whether a given number is palindrome or not.
*******************************************************************************************************/

#include <stdio.h>      //Preprocessor directives to include copy of file stdio.h

// function `power()` is used to calculate exponent of a number. It contains two arguments.
// `base` which is the number in which power `pow` is to be raised.
int power(int base, int power) {
    int store=1;

    for(; power>0; power--) {
        store = store*base;
    }
    return store;
}

//function len() is used to return the length of a number `num`
int len(int num) {
    int i = 0;
    do {
        num = num/10;
        i++;    
    } while (num>0);
    return i;
}

//function calculates the armstrong of a number `num` and uses call by reference method to return the output.
void calc_armstrong(int num, int *output) {
    int i = 1, calc = 0;
    do {
        calc = power(num % power(10, i)/power(10, i-1), len(num)) + calc; 
        i++;
    } while(i <= len(num));
    *output = calc;
}

int main(void) {
    int num, calculated;

    printf("\nEnter a number: ");                 //asking user for input 
    scanf("%d", &num);                            //takes input from the user and stores in variable `num`
    
    calc_armstrong(num, &calculated);

    if(num == calculated)
        printf("\nThe number %d is an armstrong number.", num);
    else 
        printf("\nThe number %d is not an armstrong number.", num);

    printf("\n\n");
    return 0;       //Keeping the compiler happy
}