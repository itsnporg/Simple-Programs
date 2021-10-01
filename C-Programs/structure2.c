#include<stdio.h>

struct student
{
    int roll_no,marks;
    char name[25];
}stud[100],t;

void main()
{
    int i,j,n;
    printf("Enter the no of students\n");
    scanf("%d",&n);
    printf("enter student info as roll_no , name , marks\n");
    for(i=0;i<n;i++)
    {
        scanf("%d %s %d",&stud[i].roll_no,stud[i].name,&stud[i].marks);
    }
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(stud[j].marks<stud[j+1].marks)
            {
                t=stud[j];
                stud[j]=stud[j+1];
                stud[j+1]=t;
            }
        }
    }
    
    printf("\nStudent info in terms of marks from highest to lowest\n");
    printf("\nROLL_NO\t\tNAME\t\tMARKS\n");
    printf("-------------------------------------------------------------------------------\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t\t\t%s\t\t\t%d\n",stud[i].roll_no,stud[i].name,stud[i].marks);
    }
}