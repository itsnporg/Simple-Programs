#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_IN 128
#define MAX_X 64

int main()
{
    int i;
    int upper=0,lower=0,number = 0;
    char ch[MAX_IN], chUpper[MAX_X], chLower[MAX_X], chNumber[MAX_X];
    printf("Enter the String:\n");
    gets(ch);
    printf("input given is : %s\n",ch);
    for (i=0;ch[i]!='\0';i++)
    {
        if(ch[i]>='A' && ch[i]<='Z')
        {
            chUpper[upper++]= ch[i];
        }
        else if(ch[i]>='a' && ch[i]<='z')
        {
            chLower[lower++]= ch[i];
        }
        else if(ch[i]>='0' && ch[i]<='9')
        {
            chNumber[number++]= ch[i];
        }
        if ((ch[i+1]) == ' '){
            i += 1;
        }
    }
    printf("lowercase letters: %d: %s\n",lower, chLower);
    printf("uppercase letters: %d: %s\n",upper, chUpper);
    printf("number letters: %d: %s\n",number, chNumber);
    return 0;
}