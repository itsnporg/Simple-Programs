#include <stdio.h>
#include <stdlib.h>

int main() {
    int newMatrix[10][10], row, column, size, k, tempStore = 0;
    int matrixA[10][10], matrixB[10][10];

    //Enter the size of matrix
    printf("Enter the size of the square matrix: ");
    scanf("%d", &size);

    if(size>10 || size == 0){
        printf("\n***Invalid Input. Max. Size of the matrix is 10 and Min. Size is 1***");
        exit(0);
    }

    //Entering values to the first matrix i.e. matrixA.
    printf("\nEnter the value of matrix A. Press 'Enter' after each number:\n");
    for (row = 0; row< size; row++) {
        for (int column = 0; column < size; column++) {
            scanf("%d", &matrixA[row][column]);
        }
    }

    //Entering values to the second matrix i.e. matrixB.
    printf("\nEnter the value of matrix A. Press 'Enter' after each number:\n");
    for (int row = 0; row < size; row++) {
        for (int column = 0; column < size; column++) {
            scanf("%d", &matrixB[row][column]);
        }
    }

    //Multiplying matrixA and matrixB 
    for (row = 0; row < size; row++) {
        for (column = 0; column < size; column++) {
            for (k = 0; k < size; k++) {
                tempStore += matrixA[row][k] * matrixB[k][column];
            }
            newMatrix[row][column] = tempStore;
            tempStore = 0;
        }
    }

// Displaying matrixA
    printf("\nMatrixA:\n");
    for (row = 0; row < size; row++) {
        for (column = 0; column < size; column++) {
            printf("%d\t", matrixA[row][column]);
        }
        printf("\n");
    }

// Displaying matrixB
    printf("\nMatrixB:\n");
    for (row = 0; row < size; row++) {
        for (column = 0; column < size; column++) {
            printf("%d\t", matrixB[row][column]);
        }
        printf("\n");
    }

// Displaying matrixA * matrixB = newMatrix
    printf("\nProduct of matrixA and matrixB is:: \n");
    for (row = 0; row < size; row++) {
        for (column = 0; column < size; column++) {
            printf("%d\t", newMatrix[row][column]);
        }
        printf("\n");
    }

    return 0;
}
