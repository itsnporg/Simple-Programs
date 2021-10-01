#include <stdio.h>
#include <string.h>

struct student
{
    int rollno;
    char fname[80];
    int marks;
};

void accept(struct student list[], int s);
void display(struct student list[], int s);
void bsortname(struct student list[], int s);
void bsortmarks(struct student list[], int s);

int main()
{
    struct student data[20];
    int n, choice;

    printf("Number of records you want to enter: ");
    scanf("%d", &n);

    accept(data, n);
    printf("\nBefore sorting");
    display(data, n);

    printf("\n\nChoose:\n");
    printf("To sort by name, Enter '1'\n");
    printf("To sort by marks, Enter '0'\n ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        bsortname(data, n);
    }
    else if (choice == 0)
    {
        bsortmarks(data, n);
    }
    else 
    {
        printf("Error!!! Enter either 1 or 0 !");
    }

    printf("\nAfter sorting: ");
    display(data, n);

    return 0;
}

void accept(struct student list[80], int s)
{
    for (int i = 0; i < s; i++)
    {
        printf("\n\nEnter data for Record #%d", i + 1);

        printf("\nEnter rollno : ");
        scanf("%d", &list[i].rollno);

        printf("Enter fname : ");
        scanf("%s", list[i].fname);

        printf("Enter marks : ");
        scanf("%d", &list[i].marks);

        printf("\n************************************\n");
    }
}

void display(struct student list[80], int s)
{
    printf("\n\nRollno\tfName\tMarks\n");
    for (int i = 0; i < s; i++)
    {
        printf("%d\t%s\t%d\n", list[i].rollno, list[i].fname, list[i].marks);
    }
}

void bsortname(struct student list[80], int s)
{
    int i, j;
    struct student temp;

    for (i = 0; i < s - 1; i++)
    {
        for (j = 0; j < (s - i - 1); j++)
        {
            if (strcmp(list[j].fname, list[j + 1].fname) > 0)
            {
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}

void bsortmarks(struct student list[80], int s)
{
    int i, j;
    struct student temp;

    for (i = 0; i < s - 1; i++)
    {
        for (j = 0; j < (s - i - 1); j++)
        {
            if (list[j].marks < list[j + 1].marks)
            {
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}