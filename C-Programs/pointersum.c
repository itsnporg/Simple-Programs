#include <stdlib.h>
#include <stdio.h>

int main(){
    int i,n,sum=0,*ptr;
    printf("Enter number of elements : ");
    scanf("%d",&n);
    ptr = (int*)malloc(n*sizeof(int));
    if (ptr == 0){
        printf("memory can't be allocated");
        exit(0);
    }
    for (i=0;i<n;i++){
    printf("Enter elements %d: ",i+1);
    scanf("%d",ptr+i);
    sum += *(ptr+i);
    }
    printf("Sum of numbers = %d ",sum);
    free(ptr);
    return 0;
}