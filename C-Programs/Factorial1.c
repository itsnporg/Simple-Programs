#include <stdio.h>
int main()
{
    int i, n, fakt = 1;
    printf("Enter a number:\n");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
         fakt = fakt*i;
    printf("Factorial of %d js %d\n", n, fakt);
    getch();
    
}
