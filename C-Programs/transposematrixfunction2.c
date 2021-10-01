// C Program to find transpose of a matrix
#include <stdio.h>

// This function stores transpose of A[][] in B[][]
void transpose(int N,int A[N][N])
{
    int B[N][N];
    for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			B[i][j] = A[j][i];
        }
    }
	printf("Result matrix is \n");
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
		printf("%d ", B[i][j]);
        }
		printf("\n");
	}
}

int main()
{
    int N;
    printf("Enter size for matrix (NxN): ");
    scanf("%d",&N);
    int A[N][N];  //giving size

    for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
        scanf("%d", &A[i][j]);
    }
    transpose(N, A);
    return 0;
}
