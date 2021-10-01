#include <stdio.h>

int determinant2(int matrix[2][2]){
int determinant;
determinant = matrix[0][0]*matrix[1][1] - matrix[1][0]*matrix[0][1];
printf("%d",determinant);
    }

int main(){
printf("Enter matrix");

int i,j,matrix[2][2];

for (i =0; i< 2;i++){
    for ( j = 0; j < 2; j++)
    {
        printf("Enter matrix [%d][%d] : ",i,j);
        scanf("%d",&matrix[i][j]);
    }
}
determinant2(matrix);
return 0;
}