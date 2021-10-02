#include<stdio.h>

int main()
{
    printf("\n\n\t Reverse an Array Program\t\n\n\n");

    int c, d, n, a[100], b[100];
    printf("\n\nEnter number of elements in array :");
    scanf("%d", &n);
    printf("\n\nEnter %d elements\n", n);

    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for(i = n-1, j = 0; i >= 0; i--, j++)
        b[j] = a[i];


    for(i = 0; i < n; i++)
        a[i] = b[i];

    printf("\n\n Resultant array is: ");
    for(i = 0; i < n; i++)
        printf("%d", a[i]);

    printf("\n\n\t\t\t Thanks! \n\n\n");
    return 0;
}
