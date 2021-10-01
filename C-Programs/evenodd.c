#include <stdio.h>
void main() 
{
    int number,a;
    printf("Enter a positive integer number: ");
    scanf("%d",&number);
    a= number%2;
    switch(a){
    case 0:
        printf("%d is an EVEN number.\n", number);
        break;
    case 1:
        printf("%d is an ODD number.\n", number);
        break;
    }
}