#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[10];
    int year, month, day;
} data;

int calculate_age(data user_details) {
    int age = 2021 - user_details.year;
    
    if (user_details.month > 8) {
        age -= 1;
    } else if (user_details.month == 8) {
        if (user_details.day > 11) {
            age -= 1;
        }
    }
    
    return age;
}

int main() {
    int users;
    
    printf("How many users?\n");
    scanf("%d", &users);
    
    data *user_details = malloc(users * sizeof(*user_details));
    
    for (int i = 0; i < users; ++i) {
        printf("\nEnter the details of user %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", user_details[i].name);
        printf("Date of birth (year-month-day): ");
        scanf("%d-%d-%d", &user_details[i].year, &user_details[i].month, &user_details[i].day);
    }
    
    printf("\n************************************\n");
    printf("Today is 2021-8-11.\n");
    printf("************************************\n\n");
    
    int age_arr[users];
    
    for (int i = 0; i < users; ++i) {
        age_arr[i] = calculate_age(user_details[i]);
        printf("%s is %d years old.\n", user_details[i].name, age_arr[i]);
    }
    
    free(user_details);
    
    return 0;
}