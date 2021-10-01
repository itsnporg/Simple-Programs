#include <stdio.h>

int fact(int);
void prime(int);

int main(){
    int num;
    printf("Enter number = ");
    scanf("%d",&num);
    printf("factorial is %d\n",fact(num));
    prime(fact(num));
}

int fact(int num){
    int i,fact=1;
    for(i=1;i<=num;i++){
        fact=fact*i;
    }
    return fact;
}

void prime(int fact){
    int k,count=0;
        for ( k = 2; k < fact ; k++){
            if( fact % k == 0)
            count++;
        }
        if (count == 0 ){
            printf("%d is a prime number.\n",fact);
        }
        else{
            printf("%d is not a prime number.\n",fact);
        }
}