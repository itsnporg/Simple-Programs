#include<stdio.h>
int z=0;

void recursssion(int a,int b,int t){
    int c=0;
    c = a+b;
    printf("%d  ",c);
    z = z+1;
    a=b;
    b=c;
    if (z <= (t-3)) {
        recursssion(a,b,t);
    }
}

int main(){
    int a,b,t;
    printf("Enter 2 numbers For fibonacci : ");
    scanf("%d %d",&a,&b);
    printf("Enter number of terms needed for fibonacci : ");
    scanf("%d",&t);
    printf("%d  %d  ",a,b);
    recursssion(a,b,t);
    return 0;
}