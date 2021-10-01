#include <stdio.h>
#define creditHour 3
#define TotalCreditHour (creditHour*6)

float function(float marks[],int n){
float sum=0, gradepoint=0;

for(int i=0; i<n; i++){
    if(marks[i] >= 80 && marks[i]<= 100 ){
        gradepoint += 4 * creditHour;
    }else if(marks[i] >= 60 && marks[i]<= 79 ){
        gradepoint += 3 * creditHour;
    }else if(marks[i] >= 40 && marks[i]<= 59 ){
        gradepoint += 2 * creditHour;
    }else if(marks[i] >= 20 && marks[i]<= 39){
        gradepoint += 1 * creditHour;
    }else {
        gradepoint += 0;
        }
}
return gradepoint / TotalCreditHour;

}

int main(){
    float marks[6];
    printf("Enter marks in 6 subjects : ");
    for(int i=0; i < 6; i++){
        scanf("%f",&marks[i]);
    }
    printf("Gpa is %.2f \n",function(marks,6));
}