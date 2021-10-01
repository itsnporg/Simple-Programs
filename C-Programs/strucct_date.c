#include <stdio.h>

struct date {
    int days;
    int month;
    int year;
} asked;

void display(struct date asked);

int main(){
    printf("Enter date: \n");
    printf("(In integer form)\n");
    printf("Enter month : ");
    scanf("%d",&asked.month);
    printf("Enter day : ");
    scanf("%d",&asked.days);
    printf("Enter year : ");
    scanf("%d",&asked.year);
    display(asked);
}

void display(struct date asked){
    switch(asked.month){
        case 1:
            printf("January");
            break;
        case 2:
            printf("February");
            break;
        case 3:
            printf("March");
            break;
        case 4:
            printf("April");
            break;
        case 5:
            printf("May");
            break;
        case 6:
            printf("June");
            break;
        case 7:
            printf("July");
            break;
        case 8:
            printf("August");
            break;
        case 9:
            printf("September");
            break;
        case 10:
            printf("October");
            break;
        case 11:
            printf("November");
            break;
        case 12:
            printf("December");
            break;
    }
    printf(" %d, %d",asked.days%32,asked.year);
}