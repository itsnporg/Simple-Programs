#include <stdio.h>
void main()
{
    int i,j,k,counter=0;
    for (i=5; i>=1;i--){
        counter = i;
        while (counter != 5){
            printf(" ");
            counter++;
        }
        for(j=1;j<=i;j++){
            printf("%d ",j);
        }
        for(k=(j-1-1);k>=1;k--)
            printf("%d ",k);
    printf("\n");
    }
}