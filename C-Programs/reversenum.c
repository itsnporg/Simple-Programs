#include <stdio.h>

int reverse (int f){
    int remainder,rev=0;
    while (f!=0){
        remainder = f % 10;
        rev = rev * 10 + remainder;
        f = f / 10;
        }
        return rev;
    }

void main(){
    int n;
    printf("Enter a Number\t");
    scanf("%d", &n);
    printf("Reversed number = %d\n\n",reverse(n));
}