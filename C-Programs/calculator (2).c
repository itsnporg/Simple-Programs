#include <stdio.h>
void main() {
    char operator;
    float number1, number2;
    printf("Enter an operator: ");
    scanf("%c", &operator);
    printf("Enter two numbers: ");
    scanf("%f %f", &number1, &number2);

    switch (operator) {
    case '+':
        printf("%.1f + %.1f = %.1f \n", number1, number2, number1 + number2);
        break;
    case '-':
        printf("%.1f - %.1f = %.1f \n", number1, number2, number1 - number2);
        break;
    case '*':
        printf("%.1f * %.1f = %.1f \n", number1, number2, number1 * number2);
        break;
    case '/':
        printf("%.1f / %.1f = %.1f \n", number1, number2, number1 / number2);
        break;
    default:
        printf("Entered operator is not specified.\n");
    }
}