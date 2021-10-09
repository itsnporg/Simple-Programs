#include<stdio.h>

struct student {
    char name[50];
    int roll; 
    float marks;
} s;

int main(){
    printf("Enter Information.... \n");

    printf("Enter Your Good Name: \n");
    scanf("%s",s.name);

    printf("Enter Your roll number: \n");
    scanf("%d",&s.roll);

    printf("Enter Your markrs: \n");
    scanf("%f",&s.marks);

    //Displaying the information
    printf("Name: %s\n",s.name);
    printf("Roll: %d\n",s.roll);
    printf("Marks: %f\n",s.marks);

    // signal to operating system program ran fine
    return 0;
}