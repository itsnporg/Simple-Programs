#include <stdio.h>
#include <math.h>

int todecimal(char binary[],int length){
    int decimal = 0,i,j=0;
    for (i = length - 1; i >= 0; --i,j++)
    {
        if (binary[i] == '1'){
            decimal += pow (2, j);
            printf("One discovered at : %d\n", j);
        }
    }
    return decimal;
}

void main ()
{
    char binary [20];
    int x;
    printf ("Input the binary number:  "); //take binary num as string
    scanf ("%s", binary);

    int length = 0;
    while (binary [length] != '\0')  //calculate binary num length
    ++length;

    // printf("length is %d ", length);

    x = todecimal(binary, length);
    printf ("%s to decimal = %d\n",binary,x);
}