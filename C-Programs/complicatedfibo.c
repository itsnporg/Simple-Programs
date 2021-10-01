#include "stdio.h"
int Fibonacci(int a, int b, int i){
    if(i==1){
        return a;
    }
    else if(i==2){
        return b;
    }else{
    return Fibonacci(a,b,i - 1) + Fibonacci(a,b,i - 2);
    }
}
int main(void){
    int a, b;
    printf("Input 1st and 2nd term with spaces: \t");
    scanf("%d %d", &a, &b);
    int n;
    printf("How many terms of the fibonacci sequence do you want to print? ");
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i){
        printf("%d\t", Fibonacci(a,b,i));
    }
    printf("\t");
}