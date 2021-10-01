#include <stdio.h>

int sum(int num){
    if (num != 0)
        return num + sum(num - 1);
    else
        return num;
}

void main(){
    int n;
    printf("Enter a positive number: ");
    scanf("%d", &n);
    printf("Sum = %d",sum(n));   
}