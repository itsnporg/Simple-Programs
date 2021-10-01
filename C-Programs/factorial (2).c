#include <stdio.h>

int factorial(int n){
    int fact = 1;
    for (int i = 1;i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}

void main(){
    int num;
    printf("Enter number = ");
    scanf("%d",&num);
    printf("Factorial of %d = %d \n",num,factorial(num));
}