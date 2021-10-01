//--------------------------------Program to calculate the distance between two coodinates----------------------------------------------------
#include <stdio.h>
#include <math.h>

float distance(float x1, float x2,float y1,float y2){
    float d;
    d = sqrt(pow((x1 - y1), 2) + pow((x2 - y2), 2));
    // m = (y2-y1)/(x2-x1);
    return d;
}

struct coodinates{
    float x;
    float y;
} length,length2;

void main()
{
    printf("Enter first coodinates: \n");
    scanf("%f %f", &length.x, &length.y);
    printf("Enter Second coodinates: \n");
    scanf("%f %f", &length2.x, &length2.y);
    printf("Distance between two coodinates: %.2f \n", distance(length.x, length.y, length2.x, length2.y));
}