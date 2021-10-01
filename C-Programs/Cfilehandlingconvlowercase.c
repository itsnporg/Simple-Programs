#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
//not implemented -- not running

#define FILENAME "test.txt"

int main(){
    FILE *fp = NULL;
    FILE *fp2 = NULL;
    char ch =  ' ';

    fp = fopen(FILENAME, "r");
    
    if (fp == NULL)
        return -1;

    fp2 = fopen("temp.txt", "w");

    if (fp2 == NULL)
        return -1;

    while  ((ch = fgetc(fp)) != EOF){
        if (islower(ch))
        {
            ch = ch - 'a' + 'A';
        }
        fputc (ch, fp2);
    }
    fclose(fp);
    fclose(fp2);

    //rename the temp file 
    rename("temp.txt",FILENAME);
    //remove the temp
    remove("temp.txt");

    fp = fopen(FILENAME, "r");
    if (fp == NULL)
        return -1;
    while ((ch = fgetc(fp)) != EOF)
        printf("%c", ch);

    fclose(fp);
    fp = NULL;
    fp2 = NULL;

    return 0;
}