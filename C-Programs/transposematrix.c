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