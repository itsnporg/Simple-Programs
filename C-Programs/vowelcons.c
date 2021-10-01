#include <stdio.h>
void main(){
    char x;
    printf("Enter any alphabet: ");
    scanf("%c",&x);
    switch(x){
        case 'a': 
        case 'e': 
        case 'i': 
        case 'o': 
        case 'u': 
        case 'A': 
        case 'E': 
        case 'I': 
        case 'O': 
        case 'U': 
            printf("Vowel");
            break;
        default: 
            printf("Consonant");
    }
}