#include <stdio.h>
#include <string.h>

typedef struct{
    char name[30];
    int roll;
    float marks;
}okay;

void main() {

int n,i,j;

printf("Enter number of students\n");
scanf("%d", &n);
    okay student[n];
    okay temp;
    printf("Enter roll, name and marks of student \n ");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &student[i].roll);
        scanf("%s", student[i].name);
        scanf("%f", &student[i].marks);
}
for(i=0; i<(n-1); i++){
    for(j=0; j<(n-1-i);j++){
        if (strcmp(student[j].name, student[j + 1].name) > 0){
                temp = student[j];
                student[j] = student[j + 1];
                student[j + 1] = temp;
        }       
    }     
}

printf("\nSorted data in ascending is : \n\n");
for(i=0;i<n;i++){
    printf("%d ...............\n", i+1);
    printf("Name of %d is %s\n",i+1,student[i].name);
    printf("Roll  = %d\n", student[i].roll);
    printf("Marks = %.2f\n", student[i].marks);
}
}