#include <stdio.h>

void swap(int *x,int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
};

void main(){
    int number1, number2;
    printf("Enter value for number1 : ");
    scanf("%d", &number1);
    printf("Enter value for number2 : ");
    scanf("%d", &number2);
    printf("Before Swapping: num1 is: %d, num2 is: %d\n",number1,number2);

    swap(&number1, &number2);
    printf("After Swapping: num1 is: %d, num2 is: %d\n",number1,number2);
    
}