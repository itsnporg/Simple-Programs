#include <stdio.h>

int main(){
    int a,i;
    printf("Enter the number ");
    scanf("%d",&a);
    int result = 1;
    
    for(i=1;i<=10;i++){
        result = i * a;
        printf(" %d X %d = %d \n",a,i,result );
    }

    return 0;
}