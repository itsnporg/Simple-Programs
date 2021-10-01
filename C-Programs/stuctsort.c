#include <stdio.h>

typedef struct{
    char name[30];
    int roll;
    float marks;
}okay;

void main() {

int n,temp,i,j;
printf("Enter number of students\n");
scanf("%d", &n);
    okay student[n];
printf("Enter roll, name and marks of student \n ");

for (int i = 0; i < n;i++ ){
    scanf("%d", &student[i].roll);
    scanf("%s", &student[i].name);
    scanf("%f", &student[i].marks);
}
for(i=0; i<(n-1); i++){
    for(j=0; j<(n-1-i);j++){
        if ( student[j].marks > student[j+1].marks){
    temp = student[j].marks;
    student[j].marks = student[j+1].marks;
    student[j+1].marks = temp;
        }       
    }     
}

printf("\nSorted data in ascending is : \n\n");
for(i=0;i<n;i++){
    printf("%d ...............\n", i);
    printf("Name of %d is %s\n",i,student[i].name);
    printf("Roll  = %d\n", student[i].roll);
    printf("Marks = %.2f\n", student[i].marks);
}
}