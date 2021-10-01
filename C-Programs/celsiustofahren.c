#include <stdio.h>

int main()
{
    float C, f;
    printf("Input temperature in Celsius scale: ");
    scanf("%f", &C);
    f = (C * 9 / 5) + 32;
    printf("%.2f C = %.2f F \n", C, f);
    return 0;
}
