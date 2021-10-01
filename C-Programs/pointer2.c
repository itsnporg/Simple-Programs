#include <stdio.h>

void main()
{
    int x=10, y;
    int *ptr = &x;
    y = *ptr;
    printf("%d is stored in location %x \n", x, &x);
    printf("%d is stored in location %x \n", &x, &x);
    printf("%d is stored in location %x \n", *ptr, &x);
    printf("%d is stored in location %x \n", y,&*ptr);
    printf("%x is stored in location %x \n", ptr, &ptr);
    printf("%d is stored in location %x \n", y, &y);

    *ptr = 25;
    printf("\n now  x = %d \n", x);
}