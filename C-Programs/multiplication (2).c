#include <stdio.h>
void main(){
    int n,i;
    printf("Enter the number: ");
    scanf("%d",&n);
    for(i=1;i<11;i++){
        printf("%d X %d = %d \n",n,i,n*i);
    }
}