#include <stdio.h>
#include <stdlib.h>

int determinant(int** a, int n) {
    if(n == 1) return a[0][0];
    else if(n == 2) return (a[0][0] * a[1][1]) - (a[1][0] * a[0][1]);
    else{
        int **newArr = (int**) malloc((n-1) * sizeof(int));
        int i, j;
        for(i = 0; i < n-1; i++) {
        newArr[i] = (int*) malloc((n-1) * sizeof(int));
    }
    int new_m, new_n, mn_index, det = 0;
    int row, column;
    for(mn_index = 0; mn_index < n; mn_index++) {
        new_m = 0;
        for(row = 1; row < n; row++) {
        new_n = 0;
            for(column = 0; column < n; column++) {
                if(column == mn_index)
                continue;
                else
                newArr[new_m][new_n] = a[row][column];
                new_n++;
            }
    new_m++;
        }       
    if(mn_index%2 == 0)
        det += a[0][mn_index] * determinant(newArr, new_m);
    else
        det -= a[0][mn_index] * determinant(newArr, new_m);
    }
    return det;
        }
}

int main() {
    int n, i, j;
    printf("Enter the size of square matrix: ");
    scanf("%d", &n);
    int** matrix = (int**) malloc(n * sizeof(int*));
    for(i = 0; i < n; i++)
        matrix[i] = (int*) malloc(n * sizeof(int));
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &matrix[i][j]);
    printf("The determinant of the matrix is: %d", determinant(matrix, n));
}
