#include <stdio.h>
#define SubS 6
        int func(int Grade[],int cred[]);

int main(){
    int i,Grade[6],cred[6];
printf("Input grade and credits For six subjects \n");
        // func(Grade[],cred[]);
        printf("gpa is : %d ",func(Grade,cred));
}

int func(int Grade[],int cred[]){
int i,GradeTotal=0, CredTotal=0,GPA;
        
        for (i=0; i<SubS; i++){
printf("Input grade\n");
        scanf("%d",&Grade[i]);
printf("Input credits\n");
        scanf("%d",&cred[i]);
        }
        for (i=0; i<SubS; i++){
        GradeTotal += Grade[i] * cred[i];
        CredTotal += cred[i];
        }
    GPA= GradeTotal / CredTotal;
    return GPA;// printf("Grade point average: is %d ", GPA);
        
}   