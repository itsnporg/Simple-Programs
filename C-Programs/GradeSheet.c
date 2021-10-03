#include <stdio.h>
#include <string.h>

int main(){

    int n,a;

    printf("Enter the total number of subjects ");
    scanf("%d",&n);

    char subject[n-1][20],sub;
    float marks[n-1],mar;
    char grade[n-1][3];
    float gpa[n-1], avgGpa,gpaSum;
    char finalGrade[3];

    for(a=0;a<n;a++){
        printf("Enter Subject and marks out of 100 (Seperated by space) ");
        scanf("%s %f",subject[a],&marks[a]);
    }

    for(a=0;a<n;a++){
        if(marks[a]>90){
            strcpy(grade[a],"A+");
            gpa[a] = 4;
        }
        else if(marks[a]<90 && marks[a]>80){
            strcpy(grade[a], "A");
            gpa[a]= 3.6;
        }
        else if(marks[a] < 80 && marks[a] > 70)
        {
            strcpy(grade[a], "B+");
            gpa[a] = 3.2;
        }
        else if (marks[a] < 70 && marks[a] > 60)
        {
            strcpy(grade[a], "B");
            gpa[a] = 2.8;
        }
        else if (marks[a] < 60 && marks[a] > 50)
        {
            strcpy(grade[a], "C+");
            gpa[a] = 2.4;
        }
        else if (marks[a] < 50 && marks[a] > 40)
        {
            strcpy(grade[a], "C");
            gpa[a] = 2.0;
        }
        else if (marks[a] < 20 && marks[a] > 40)
        {
            strcpy(grade[a], "D");
            gpa[a] = 1.6;
        }
        else if (marks[a] < 1 && marks[a] > 20)
        {
            strcpy(grade[a], "E");
            gpa[a] = 0.8;
        }else{
            strcpy(grade[a], "NA");
            gpa[a] = 0;
        }
    }

    gpaSum = 0;
    printf("\n\nSubject\t Marks\t Grade\t GPA\n");
    for (a = 0; a < n; a++)
    {   
        gpaSum=gpaSum+gpa[a];
        printf("%s\t %.2f\t %s\t %.1f\n", subject[a], marks[a], grade[a],gpa[a]);
    }
    avgGpa = gpaSum/n;

    for (a = 0; a < n; a++)
    {
        if (avgGpa > 3.6)
        {
            strcpy(finalGrade, "A+");
        }
        else if (avgGpa < 3.6 && avgGpa > 3.2)
        {
            strcpy(finalGrade, "A");
        }
        else if (avgGpa < 3.2 && avgGpa > 2.8)
        {
            strcpy(finalGrade, "B+");
        }
        else if (avgGpa < 2.8 && avgGpa > 2.4)
        {
            strcpy(finalGrade, "B");
        }
        else if (avgGpa < 2.0 && avgGpa > 1.6)
        {
            strcpy(finalGrade, "C+");
        }
        else if (avgGpa < 1.6 && avgGpa > 0.8)
        {
            strcpy(finalGrade, "C");
        }
        else if (avgGpa < 0.8 && avgGpa > 0)
        {
            strcpy(finalGrade, "D");
        }
        else
        {
            strcpy(finalGrade, "NA");
        }
    }
        printf("\nYour Avergae Grade Point GPA) is %.2f", avgGpa);
        printf("\nYour Final Grade is %s", finalGrade);

        return 0;
}