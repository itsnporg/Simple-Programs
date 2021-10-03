#include <stdio.h>
int main() {
  char op;
  long first, second;
  printf("Enter an operator (+, -, *, /, %%) : " );
  scanf("%c", &op);
  printf("Enter two operands: ");
  scanf("%ld %ld", &first, &second);

  switch (op) {
    case '+':
      printf("%ld+ %ld = %ld", first, second, first + second);
      break;
    case '-':
      printf("%ld - %ld = %ld", first, second, first - second);
      break;
    case '*':
      printf("%ld * %ld = %ld", first, second, first * second);
      break;
    case '/':
      printf("%ld / %ld = %ld", first, second, first / second);
      break;
    case '%':
      printf("(%ld /100)* %ld = %ld", first, second, (first* second)/ 100);
      break;
    default:
      printf("Error! operator is not correct");
  }

  return 0;
}