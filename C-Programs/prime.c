#include <stdio.h>
int main()
{
    int primes[50];
    int primeindex = 0;
    int i,j;
    printf("Prime numbers till 100 :\n");
    for (i=2; i <= 100; i++)
    {
    int count = 0;
    int c= i/2;
        for ( j = 2; j <= c ; j++)
        {
            if( i % j == 0)
            count++;
        }
        if (count == 0 )
        {
            primes[primeindex]=i;
            ++primeindex;
        }
    }
    for(i=0;i<primeindex;i++)
    {
    printf("%d ",primes[i]);
    }
    return 0;
}
