#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>

int fact(int);

void main(){
        int x,n,i;
        float a=0,z;
        printf("Enter x and n:");
        scanf("%d %d",&x,&n);
        for(i=1;i<=n;i++){
        z=pow(x,2*i-1)/fact(2*i-1);
        a=a+(z*pow(-1,i+1));
        }
        printf("Sin(%d)=",x);
        printf("%f",a);
        }

int fact(int a){
    int x=1,i;
    if(a==0||a==1){
    return 1;
    }else{
    for(i=a;i>1;i--){
    x=x*i;
    }
    return x;
    }
}