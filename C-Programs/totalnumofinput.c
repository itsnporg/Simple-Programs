#include <stdio.h>
#include <string.h>

void main(){
    char mystr[5];
    scanf("%s",mystr);
    printf("Max Length that user can give is : %ld\n",strlen(mystr));
    int counter = 0;
    for(int i=0;i<100;i++)
    {
        counter += 1;
        if (mystr[i]=='\0')
        break;
    } 
    printf("Total number including \"\\0\" in array is : %d",counter);
}   