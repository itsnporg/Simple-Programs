#include <stdio.h>
void main(){
    int i,j,k,l;
    for (i=1;i<6;i++){
        for (j=1;j<=i;j++){
            printf("%d \t",j);
        }
        printf("\n");
    }
    for (k=4;k>0;k--){
        for (l=1;l<=k;l++){
            printf("%d \t",l);
        }
        printf("\n");
    }
}