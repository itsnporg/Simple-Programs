#include <stdio.h>
int main()
{
    int i, marks[5], total=0, average;
    printf("Note: \nMarks 1=English\t\tMarks 2=Math\nMarks 3=Computer\tMarks 4=Physics\n\t\tMarks 5=Chemistry\n");
    for (i=0; i<5; i++) {
        printf("\nEnter Marks %d:\t", i+1);
        scanf("%d", &marks[i]);
    }
    for (int i = 0; i < 5; i++) {
        total = total + marks[i];
    }
    average = total/5;
    printf("Total marks obtained is: %d", total);
    printf("\nAverage marks obtained is: %d", average);

    return 0;
}
