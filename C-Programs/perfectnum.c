/* 1.program to identify whether the given number is a perfect number or not using a
function. 28 is a perfect number.   */

#include <stdio.h>

int perfect (int s){
    int b = 1, sum = 0;
    while (b<s){
        if ((s % b) == 0){
            sum = sum + b;
        }
            b++;
    }
        return sum;
}

int main(){
    int num, x;
    printf("Enter an integer value\t");
    scanf("%d", &num);
    x = perfect(num);
    if(x==num)
        printf("The number %d is a perfect number\n", num);
    else
        printf("The number %d is not a perfect number\n", num);
    return 0;
}
