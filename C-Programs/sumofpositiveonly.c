#include<stdio.h>
int main()
{
	int n=0,sum=0;
    do
	{
        sum += n;   
        printf("Enter positive number to sum and negative to terminate: ");
        scanf("%d",&n);     
	}while (n>=0);
	printf("The Sum is: %d",sum);
	return 0;
}