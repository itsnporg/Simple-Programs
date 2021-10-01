#include <stdio.h>

    int fact(int);
    int prime(int);

int main(){
    int value,z,s;
    printf("enter number : ");
    scanf("%d",&value);
    z= fact(value);
    s=prime(z);
    if(s==2)
    printf("%d is a prime number",z);
    else
    printf("%d is not a prime number",z);
}

int fact(int k){
    int i,f=1;
    for(i=k;i>0;i--){
        f *= i;
    }
    return f;
}

int prime(int t){
    int count,k;
for (int k=2; k < t ; k++){
            if( t % k == 0)
            count++;
        }
        if (count == 0){
        return 2;
        }
        else{
        return 0;
        }
}