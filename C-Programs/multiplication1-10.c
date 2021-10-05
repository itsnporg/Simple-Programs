#include<stdio.h>
#include<conio.h>

int main()
{
	 int i, j, product;
	 for(i=1;i<=10;i++)
	 {
		  for(j=1;j<=10;j++)
		  {
			   product = i*j;
			   printf("%d x %d = %d\t", i, j, product);
		  }
		  printf("\n");
	 }
	 return(0);
}