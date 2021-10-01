#include <stdio.h>

void add(int A[10][10],int B[10][10],int N,int M){
	printf("SUM of  matrix is \n");
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
		printf("%d ", (A[i][j]+B[i][j]));
        }
		printf("\n");
	}
}

int main()
{
    int A[10][10],B[10][10],N,M;
    printf("Enter size for matrix (NxM): "); //asking size
    scanf("%d %d",&N,&M);

    //taking matrix datas for N x M of A[][] & B[][]
    printf("Enter values for A[%d][%d]\n", N, M);
    for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++)
        scanf("%d", &A[i][j]);
    }
    printf("Enter values for B[%d][%d]\n", N, M);
    for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++)
        scanf("%d", &B[i][j]);
    }

    add(A, B, N, M);
    return 0;
}
