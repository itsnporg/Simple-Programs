/*??Error ????????????????????????????????????????????????????????????*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char name[50];
    int roll_no;
    char department[50];
    char school[50];
}students;

int main()
{
    students student;

    //taking inputs
    printf("Enter Name : ");
    // scanf("%[^\n]", student.name);
    fgets(student.name,50,stdin);
    //scanf("%s", student.name);
    
    printf("\nEnter Roll Number format(_ _) : ");
    scanf("%d", &student.roll_no);

    printf("\n\n%s\n\n%s\n\n%s\n\n%s%s", "Departments in KU are:",
        "Engineering:",
        "1.Chemical Engineering 2.Mechanical Engineering 3.Computer Engineering 4.Environmental Engineering Electrical Engineering",
        "Science:",
        "1.ARCHITECTURE 2.Computer Science 3.Biotechnology 4.Pharmacy");

    printf("\n\nEnter Department : ");
    // scanf("%[^\n]",student.department);
    fgets(student.department,50,stdin);

    printf("\nEnter School (SOS/SOE) : ");
    scanf("%s",student.school);
    // fgets(student.school, 50, stdin);

//check--- for department and roll no
    if (!strcmp((student.department), "CHEMICAL ENGINEERING"))
    {
        printf("Name : %s \t",student.name);
        
        printf("\n%sUNG%s00%d", student.school, "CHE", student.roll_no);
    }
    if (!strcmp((student.department), "COMPUTER ENGINEERING"))
    {
        printf("Name : %s \t",student.name);
        
        printf("\n%sUNG%s00%d", (student.school), "CE", student.roll_no);
    }
    if (!strcmp((student.department), "MECHANICAL ENGINEERING"))
    {
        printf("Name : %s \t",student.name);
        
        printf("\n%sUNG%s00%d", student.school, "ME", student.roll_no);
    }
    if (!strcmp((student.department), "ENIVIRONMENTAL ENGINEERING"))
    {
        printf("Name : %s \t",student.name);
        
        printf("\n%sUNG%s00%d", student.school, "ENE", student.roll_no);
    }
    if (!strcmp((student.department), "ELECTRICAL ENGINEERING"))
    {
        printf("Name : %s \t",student.name);
        
        printf("\n%sUNG%s00%d", student.school, "CHE", student.roll_no);
    }
    if (!strcmp((student.department), "ARCHITECTURE"))
    {
        printf("Name : %s \t",student.name);
        
        printf("\n%sUNG%s00%d",student.school, "AR", student.roll_no);
    }
    if (!strcmp((student.department), "COMPUTER SCIENCE"))
    {
        printf("Name : %s \t",student.name);
        
        printf("\n%sUNG%s00%d", student.school, "CS", student.roll_no);
    }
    if (!strcmp((student.department), "BIOTECHNOLOGY"))
    {
        printf("Name : %s \t",student.name);
        
        printf("\n%sUNG%s00%d", student.school, "BT", student.roll_no);
    }
    if (!strcmp((student.department), "PHARMACY"))
    {
        printf("Name : %s \t",student.name);
        
        printf("\n%sUNG%s00%d", student.school, "PH ENGINEERING", student.roll_no);
    }

    return 0;
}