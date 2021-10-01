#include <stdio.h>
void main()
{
    int i,n,f,c,d;
    printf("Enter Numbers of values Needed : ");
    scanf("%d",&n);
    i=1;
    f=0;
    c=1;
    d=1;
    do{
        i++;
        printf("%d\n",f);
        c=d;
        d=f;
        f=c+d;
    } while(i<=n);
}