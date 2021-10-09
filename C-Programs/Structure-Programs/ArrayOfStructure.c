#include<stdio.h>
#include<string.h>
#define MAX 2

struct student
{
    char name[20];
    int roll_no;
    float marks;
}arr_student[MAX];

int main()
{
    // struct student arr_student[MAX];
    int i;

    for(i = 0; i < MAX; i++ )
    {
        printf("\nEnter details of student %d\n\n", i+1);

        printf("Enter name: ");
        scanf("%s", arr_student[i].name);

        printf("Enter roll no: ");
        scanf("%d", &arr_student[i].roll_no);

        printf("Enter marks: ");
        scanf("%f", &arr_student[i].marks);
    }

    printf("\n");

    printf("Name\tRoll no\tMarks\n");

    for(i = 0; i < MAX; i++ )
    {
        printf("%s\t%d\t%.2f\n",
        arr_student[i].name, arr_student[i].roll_no, arr_student[i].marks);
    }

    // signal to operating system program ran fine
    return 0;
}