#include<stdio.h>
int main() {
	float radius, area, circumference;
	printf("Enter the radius of Circle : ");
	scanf("%f", &radius);
	area = 3.14 * radius * radius;
    circumference = 2 * 3.14 * radius;
	printf("Area of Circle : %.2f \n", area);
    printf("Circumference of Circle : %.2f \n",circumference);
	return (0);
}