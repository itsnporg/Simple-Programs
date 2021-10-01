#include <stdio.h>
#include <stdlib.h>

struct employee {
char name[30];
char date[15];
float salary;
};

int main(){
    struct employee emp ={"Nisham","7/11/21",98234.12};
    printf("\n Name : %s\n",emp.name);
    printf("\n Join Date : %s\n",emp.date);
    printf("\n Salary : %.2f\n",emp.salary);

    printf(" Enter employee information: \n");
    printf(" Name: ");
    scanf("%s",emp.name);
    printf("\n Join Date :");
    scanf("%s",emp.date);
    printf("\n Salary : ");
    scanf("%f",emp.salary);

    printf("\n Name : %s\n",emp.name);
    printf("\n Join Date : %s\n",emp.date);
    printf("\n Salary : %.2f\n",emp.salary);


    return 0;
} 