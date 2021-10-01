#include <stdio.h>   //Program to print sum

void main(){
    int matrix[2][2]; //matrix
    int matrix2[2][2]; //2nd matrix
    int i,j;
    for (i = 0; i < 2; i++){
            for (j = 0; j < 2; j++)
        {
        printf("enter matrix [%d] [%d] ",i,j);
        scanf("%d",&matrix[i][j]);
        }
    }
    for (i = 0; i < 2; i++){
            for (j = 0; j < 2; j++)
        {
        printf("enter matrix2 [%d] [%d] ",i,j);
        scanf("%d",&matrix2[i][j]);
        }
    }

printf("SUM =  \n");
int temp[2][2];
// int *ptr;
for (int c = 0; c < 2; c++) { 
    for (int d = 0; d < 2; d++){ 
    temp[c][d] =   matrix2[c][d] + matrix[c][d]; //storing the result
    printf("%d\t", temp[c][d]); 
    }
    printf("\n"); //linegap
}
printf("\n");

printf("DIFFERENCE =  \n");
// int *ptr;
for (int c = 0; c < 2; c++) { 
    for (int d = 0; d < 2; d++){ 
    temp[c][d] =   matrix[c][d] - matrix2[c][d]; //storing the result
    printf("%d\t", temp[c][d]); 
    }
    printf("\n"); //linegap
}
}