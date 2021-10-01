#include <stdio.h>
int main()
{
    int marks1,marks2,marks3,marks4,marks5,avg;
    printf("Enter your marks ");
    scanf("%d %d %d %d %d",&marks1,&marks2,&marks3,&marks4,&marks5);
    avg = (marks1 + marks2 + marks3 + marks4 + marks5) / 5;
    if(marks1>100 || marks2 >100 || marks3 > 100 || marks4 > 100 || marks5 >100)
    {
        printf("Your marks is greater than hundred which is not possible!!");
    }
    else if(marks1<50 || marks2 < 50 || marks3 <50 || marks4 < 50 || marks5 <50)
    {
        printf("Sorry you are fail!");
    }
    else if(avg>=50 && avg<55)
    {
        printf("Grade D");
    }
    else if(avg>=55 && avg<60)
    {
        printf("Grade C-");
    }
    else if(avg>=60 && avg<65)
    {
        printf("Grade C");
    }
    else if(avg>=65 && avg<70)
    {
        printf("Grade C+");
    }
    else if(avg>=70 && avg<75)
    {
        printf("Grade B-");
    }
    else if(avg>=75 && avg<80)
    {
        printf("Grade B");
    }
    else if(avg>=80 && avg<85)
    {
        printf("Grade B+");
    }
    else if(avg>=85 && avg<90)
    {
        printf("Grade A-");
    }
    else
    {
        printf("Grade A");
    }
    return 0;
}