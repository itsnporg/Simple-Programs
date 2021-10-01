#include <stdio.h>
// Create a structure named Date having day, month and year as its elements.
//  Store the current date in the structure.
//  Now add 50 days to the current date and display the final date.


void main() {
struct Date {
    int day;
    int month;
    int year;
} dates;

    printf("Enter Current Date: (dd/mm/yyyy) \n");
    scanf("%d %d %d", &dates.day, &dates.month, &dates.year);

    for (int i = 1; i < 50; i++){
        dates.day += 1;

        if (dates.month > 12){
            printf("\n-----------------Year Change----------------\n");
            dates.month = 1;
            dates.year += 1;
            if (dates.day > 30){
            printf("\n-----------------Month Change--------------\n");
            dates.month += 1;
            dates.day = 1;
            }
        }

        if (dates.day > 30){
            dates.day = 1;
            dates.month +=1;
            printf("\n-----------------Month Change--------------\n");
                if (dates.month > 12){
            printf("\n-----------------Year Change---------------\n");
                dates.month = 1;
                dates.year +=1 ;
                }
        }

        printf("Day is : %d    ", dates.day);
        printf("Month is : %d    ", dates.month);
        printf("Year is : %d\n", dates.year);
        printf("\n");
    }
}