#include <stdio.h>

int main()
{
  int sal[10],c,i,j;
  for(i=0;i<10;i++)
  {
    printf("\nEnter salary of %d  person = ",i+1);
    scanf("%d",&sal[i]);
  }
  for(i=0;i<10;i++)
  { 
    
        for(j=i+1; j<10; j++)
        {
            if(sal[i] > sal[j])
            {
                c = sal[i];
                sal[i] = sal[j];
                sal[j] = c;
            }
        }
  }
  
  printf("\nSalary in accending order \n");
 for (i = 0; i < 10; ++i)
 { 
  
    printf("%d \t", sal[i]); 
 }
}
