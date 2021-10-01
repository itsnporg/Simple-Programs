#include <stdio.h>
#define N 10

void main(){
    int a[N] = {1, 3, 4, 5, 6, 9, 10, 12, 13,14}; //for sorted array

    int i, j,k;
    printf("Enter the key for searching : ");
    scanf("%d",&k);
    i = 0;
    j = N - 1;

    while(i<j){
        if((a[i] + a[j]) == k)
        {
            printf("%d + %d = %d\n", a[i],a[j],k);  //to check if sum is equal to the key
            i++;
            j--;
        }
        else if((a[i]+a[j]) < k){
            i++;
        }
        else{
            j--;
        }
    }
}