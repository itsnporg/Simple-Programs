#include<stdio.h>
#include<conio.h>

void main()
{
    FILE *fp;
    char ch;
    int size = 0;

    fp = fopen("MyFile.txt", "r");
    if (fp == NULL)
    {
        printf("\nFile unable to open...");
    }
    else
    {
        printf("\nFile opened...");
    }
    fseek(fp, 0, 2);    /* File pointer at the end of file */
    size = ftell(fp);   /* Take a position of file pointer in size variable */
    printf("The size of given file is: %d\n", size);
    fclose(fp);
}
