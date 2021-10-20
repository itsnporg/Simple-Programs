#include <stdio.h>

int main(void)
{
    int last, mid, first, flag = 1;
    int searched, numbers[] = {1, 3, 5, 6, 9, 44, 100, 112, 444, 555, 999, 2191}; //example: sorted numbers
    int sizeofarray = sizeof(numbers) / sizeof(int);
    printf("Enter number to search : ");
    scanf("%d", &searched);
    first = 0;
    last = sizeofarray - 1;

    while (flag == 1)
    {
        mid = (first + last) / 2;
        if (searched == numbers[mid])
        {
            printf("%d is found at index %d\n", searched, mid);
            flag = 0;
        }
        if (searched < numbers[mid])
        {
            first = first;
            last = mid - 1;
        }
        else
        {
            first = mid + 1;
            last = last;
        }
    }
}
