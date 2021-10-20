#include <stdio.h>
int main() {
    int num, div, quotient, remainder;
    printf("Enter num: ");
    scanf("%d", &num);
    printf("Enter divisor: ");
    scanf("%d", &div);
    quotient = num / div;
    remainder = num % div;
    printf("Quotient = %d\n", quotient);
    printf("Remainder = %d", remainder);
    return 0;
}
