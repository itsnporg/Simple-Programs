#include <stdio.h>

int main()
{
  int age[10],c=0,i;
  for(i=0;i<10;i++)
  {
    printf("\nEnter age of %d  person = ",i+1);
    scanf("%d",&age[i]);

 
    if(age[i]>=50 && age[i]<=60)
    {
      c=c+1;
    }
  }
  printf("\nNo.of persons in the age group 50 to 60 is %d",c);
}
