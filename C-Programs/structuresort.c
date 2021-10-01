#include <stdio.h>

struct student{
    int roll;
    char name[30];
    int marks;
}stud[100],t;

void main() 
{
    int i, j, n;
    printf("Enter num of Students\n");
    scanf("%d",&n);
    printf("Enter Roll, name, marks\n");
    for (i = 0; i < n;i++)
    {
    scanf("%d %s %d",&stud[i].roll,&stud[i].name,&stud[i].marks);
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1;j++)
        {
            if (stud[j].marks > stud[j+1].marks)
            {
                t = stud[j];
                stud[j] = stud[j + 1];
                stud[j + 1] = t;
            }
        }
    }
printf("\nStudent Info in term of ascending order:\n");
printf("\nRoll No\t\t Name\t\t Marks\n");
printf("_____________________________________________________\n");
for (i = 0; i < n; i++)
{
    printf("%d\t\t %s\t\t %d\n", stud[i].roll, stud[i].name, stud[i].marks);
}
}

