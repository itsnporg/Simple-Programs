#include <stdio.h>
#include <string.h>


int main(void)
{
    //reverse string (without function):

    char a[100];
    char b[100];
    int l = 0;
    int i;
    printf("Enter the string to reverse : ");
    gets(a);
    for (i = 0; a[i] != '\0'; i++)
    {
        l++;
    }

    int count = l - 1;
    for (i = 0; i <= l - 1; i++)
    {
        b[count] = a[i];
        count--;
    }
    printf("%s\n", b);

    // using the inbuilt function to reverse string

    strrev(a);
    printf("%s", a);
}
