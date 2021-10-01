#include <stdio.h>

#define EOLN '\n'
void reverse(void);  //function prototype
void main(){
    printf("enter text \n");
    reverse();
}

void reverse(void)
// read a line of characters and write it out backward
{
    char c;
    if ( (c = getchar()) != EOLN) reverse();
    putchar(c);
    return;
}