/* To convert Temperature from Farenheit to Celcius and celcius to farenhrit */

#include <stdio.h>
#include <conio.h >
int main()
{
	int a;
	float f;
    float c;
	printf("Type 1 to conver celcius to farenheit \n");
	printf("Type 2 to convert farenheit to celcius \n");
	printf("Enter your Choice ");
	scanf("%d",&a);
	
	switch(a)
	{
		case 1:
		printf("Enter the temperature in Celcius ");
		scanf("%f",&c);
		f=((9*c)/5)+32;
		printf("The temperature in farenheit is %f",f);
		break;
		
		case 2:
		printf("Enter the temperature in farenheit ");
		scanf("%f",&f);
		c= ((5*f)/9)-32;
		printf("The temperature in celcius is %f",c);
		break;
		
		default:
			printf("please make a valid choice");
	}
	
	return 0;
	
}
