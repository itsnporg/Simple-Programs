#include <stdio.h>
#define CREDIT_HOUR 3
#define TOTAL_CREDIT_HOURS (CREDIT_HOUR * 6)

float gpa(float marks[], int n) {
    float sum = 0, grade_points = 0;
    
    for(int i = 0; i < n; ++i) {
        if (marks[i] >= 80 && marks[i] <= 100) {
            grade_points += 4 * CREDIT_HOUR; // grade point 4 for 80-100
        } else if (marks[i] >= 60 && marks[i] <= 79) {
            grade_points += 3 * CREDIT_HOUR; // grade point 2 for 60-79
        } else if (marks[i] >= 40 && marks[i] <= 59) {
            grade_points += 2 * CREDIT_HOUR; // grade point 3 for 40-59
        } else if (marks[i] >= 20 && marks[i] <= 39) {
            grade_points += 1 * CREDIT_HOUR; // grade point 1 for 20-39
        } else {
            grade_points += 0;
        }
    }
    
    return grade_points / TOTAL_CREDIT_HOURS;
}

int main() {
    float marks[6];
    
    printf("Enter your marks in six subjects: ");
    for(int i = 0; i < 6; ++i) {
        scanf("%f", &marks[i]);
    }
    
    printf("Your GPA is %.2f\n", gpa(marks, 6));
}