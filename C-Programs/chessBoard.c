#include <stdio.h>
int main()
{
    int i, j, temp;
    int color1 = 219, color2 = 255; //color1's initial value represents white and color2's initial value represents black in ASCII

    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%c", color1);
            printf("%c", color2);
        }
        // code below swaps the color codes
        temp = color1;
        color1 = color2;
        color2 = temp;
        printf("\n");
    }
}