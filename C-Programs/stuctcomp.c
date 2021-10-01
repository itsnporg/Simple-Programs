#include <stdio.h>

typedef struct{
int roll;
float marks;
}okay;

void main() {
int x;
okay student1 = {222,88.12};
okay student2 = {154,77.30};
if ((student1.roll == student2.roll) && (student1.marks == student2.marks)){
    x= 0;
}
else if ((student1.roll > student2.roll) && (student1.marks >= student2.marks)){
    x= 1;
}
else
    x= -1;

if(x == 0) {
printf("\nstudent1 and student2 are same\n\n");
printf("%d %s %f\n", student1.roll,student2.marks);
}
else if (x == -1){
printf("\nstudent1 is smaller than student2\n\n");
}
else{
    printf("Student1 is larger than student2");
}
}