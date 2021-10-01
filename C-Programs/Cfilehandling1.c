#include <stdio.h>
#include <stdlib.h>

#define FILENAME "Text.txt"

int main(){
    FILE *fp = NULL;
    char ch;
    int linescount = 0;

    fp = fopen(FILENAME, "r");
    if(fp == NULL){
        printf("FILE DOESN'T EXIST\n");
        return -1;
    }
    while((ch=fgetc(fp))!= EOF)
    {
        if(ch=='\n')
            linescount++;
    }

    fclose(fp);
    fp = NULL;

    printf("Total Number of Lines are: %d\n", linescount);
    return 0;
}