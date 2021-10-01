#include <stdio.h>
#include <stdlib.h>

int avg(int *k){

    int i,sum=0;
    float c;
    for (i = 0; i < 5; i++){
        sum += *(k + i);
    }
    c = (float)sum / 5;
    printf("Avg = %.2f ",c);
}

int main(){
    int a[5];
    printf("Input 5 numbers: \n");
    for (int i = 0; i < 5; i++){
        scanf("%d",&a[i]);
        }
    avg(a);
    return 0;
}