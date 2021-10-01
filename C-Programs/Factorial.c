#include <stdio.h>
int main() {
    int n, i;
    long factorial = 1;
    printf("Enter an integer: ");
    scanf("%d", &n);

    
    if (n < 0)
        printf("Error! Cannot calculate Factorial of a negative number");
    else {
        for (i = 1; i <= n; ++i) {
            factorial *= i;
        }
        printf("Factorial of %d = %ld", n, factorial);
    }

    return 0;
}