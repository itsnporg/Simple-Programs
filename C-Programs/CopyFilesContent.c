#include <stdio.h>
#include <conio.h>

int main(void)
{
    FILE *p1; //source file pointer
    FILE *p2; //target file pointer
    char ch[100];
    char filenameS[100], filenameT[100];

    printf("Enter the filename you want to write (Sourcefile) : ");
    scanf("%s", &filenameS);

    printf("Enter the filename you want to copy to (Targetfile):");
    scanf("%s", &filenameT);

    //opening to write content on source file(optional)

    p1 = fopen(filenameS, "w+");
    fflush(stdin);
    printf("Enter the text to store in file : ");
    gets(ch);
    fputs(ch, p1);
    fclose(p1);

    //-------------------------------------------------------------
    // copying the content of source file to target file

    p2 = fopen(filenameT, "w+");
    p1 = fopen(filenameS, "r+");
    while (!feof(p1))
    {
        fgets(ch, 100, p1);
        fputs(ch, p2);
    }
    fclose(p1);
    fclose(p2);

    //------------------------------------------------------------

    //opening to view content on target file(optional)
    p2 = fopen(filenameT, "r");
    printf("content of copied file is : ");
    while (!feof(p2))
    {
        fgets(ch, 100, p2);
    }
    printf("%s", ch);
    fclose(p2);
}
