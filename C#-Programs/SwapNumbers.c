#include<stdio.h>

int main() {
   
  double firstNum, secondNum, temp;

  printf("Enter number 1: ");
  scanf("%lf", &firstNum);

  printf("Enter number 2: ");
  scanf("%lf", &secondNum);

  temp = firstNum;
  firstNum = secondNum;
  secondNum = temp;

  printf("\n After swapping >>>>>>>> \n");
  printf("Number 1 : %.2lf\n", firstNum);
  printf("Number 2 : %.2lf", secondNum);

  return 0;
}