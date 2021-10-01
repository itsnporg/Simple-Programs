#include <stdio.h> 
#include <conio.h>
int fibo(int count)
{
    static int f1=1,f2=1;
    int f; 
    f=(count<3)?1:f2+f1;
    f2=f1;
    f1=f;
    return f;
}
main(){
    system("cls");
    int count,n;
    printf("how many numbers: ");
    scanf("%d",&n);
    for (count=1;count<=n;count++)
    printf("count=%d f=%d \t",count,fibo(count));
}