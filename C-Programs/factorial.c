#include <stdio.h>

int main()
{
  int i,fac=1,num;
  printf("Enter a number to calculate factorial");
  scanf("%d",&num);

    for(i=1;i<=num;i++)
    {
      fac=fac*i;
    }

   printf("Factorial of %d is: %d",num ,fac);

  return 0;
}
