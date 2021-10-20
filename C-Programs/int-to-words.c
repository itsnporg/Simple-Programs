#include <stdio.h>
#include <string.h>

/*
Program that converts numbers to words (Example: 555 -> five hunderd fifty five)
range: 0-99,99,99,99,99,999
*/

const char *oneToNineteen[19] = {"one ", "two ", "three ", "four ", "five ", "six ", "seven ", "eight ", "nine ", "ten ", "eleven ", "twelve ", "thirteen ", "fourteen ", "fifteen ", "sixteen ", "seventeen ", "eighteen ", "nineteen "};
const char *multiplesOfTen[8] = {"twenty ", "thirty ", "fourty ", "fifty ", "sixty ", "seventy ", "eighty ", "ninety "};
const char *powersOfTen[6] = {"hundred ", "thousand ", "lakh ", "crore ", "arab ", "kharab "};

void match(unsigned long long num, int power, char *words){
    char temp[500];
    if (num < 20)
        strcpy(temp, oneToNineteen[num - 1]);
    else{
        strcpy(temp, multiplesOfTen[num / 10 - 2]);
        if (num % 10)
            strcat(temp, oneToNineteen[num % 10 - 1]);
    }
    if (power)
        strcat(temp, powersOfTen[power - 1]);
    strcat(temp, words);
    strcpy(words, temp);
}

void belowThousand(unsigned long long num, char *words){
    unsigned long long hundreth = num / 100;
    match(num % 100, 0, words);
    if (hundreth)
        match(hundreth, 1, words);
}

void toWords(unsigned long long num, char *words){
    if (!num){
        strcpy(words, "zero");
        return;
    }
    belowThousand(num % 1000, words);
    int place = 2;
    for (int i = num / 1000; i > 0; i /= 100)
        match(i % 100, place++, words);
}

int main(){
    char inwords[500] = "";
    unsigned long long a;
    printf("Enter a number: ");
    scanf("%llu", &a);
    toWords(a, inwords);
    printf("%s\n", inwords);
}
