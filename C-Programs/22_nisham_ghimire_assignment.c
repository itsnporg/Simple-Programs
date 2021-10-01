//DETERMINANT OF A MATRIX
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

//TRANSPOSE OF A MATRIX

#include <stdio.h>   //Program to print transpose of a Matrix of size [3][4];
#include <stdlib.h>
void main(){

    int matrix[3][4]={1,2,3,4,5,6,7,8,9,10,11,12}; //matrix
    int c,d,transpose[4][3]; //next matrix
    
    printf("Transpose of the matrix :\n");

for (c = 0; c < 4; c++) { //row+1 [4] as row+
    for (d = 0; d < 3; d++){ //cloumn-1 [3] as column-
        
        transpose[c][d]=matrix[d][c]; //storing the result
    printf("  %d  ", *(*(transpose + c)+d)); //final sum print
    }   
    printf("\n"); //linegap
}
}

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

//MATRIX SUM AND DIFFERENCE

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

//MATRIX MULTIPLICATION 

#include <stdio.h>

int main(){
    int c[3][3],a[3][3],b[3][3],i=0,k=0,j=0,sum=0; 
printf("Enter first matrix a : \n");
for (i=0;i<3;i++){
    for(j=0;j<3;j++){
        scanf("%d",&a[i][j]);
    }
}
printf("Enter first matrix b : \n");
for (i=0;i<3;i++){
    for(j=0;j<3;j++){
        scanf("%d",&b[i][j]);
    }
}
for (i=0;i<3;i++){
    for (j=0;j<3;j++){
            for (k = 0; k < 3; k++){
                sum += a[i][j] * b[j][k];
                // *(*c(i)+k) += *(*a(i)+k) + *(*b(i)+k);
            }
                c[i][j] = sum;
                sum =0;
    }
}

printf("MULTIPLICATION = \n");
for (i=0;i<3;i++){
    for(j=0;j<3;j++){
        printf("%d\t",c[i][j]);
    }
    printf("\n");
}


return 0;
}
