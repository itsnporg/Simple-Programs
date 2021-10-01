#include <stdio.h>
#include <math.h>

struct points {
    int x;
    int y;
} two;

float dist(struct points two){
    return (sqrt(pow(two.x, 2) + pow(two.y, 2)));
};

int main() {
    printf("Enter 1st coordinate points : ");
    scanf("%d %d", &two.x,&two.y);
    printf("\nThe distance between the points and origin is: %.2f units.",dist(two));
}

