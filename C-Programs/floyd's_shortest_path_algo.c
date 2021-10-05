#include <stdio.h>
#include <stdlib.h>

int v, e, weight_mat[30][30];

int min(int x, int y){
    return x < y ? x : y;
}

void floyds(){
    int i, j, k;
    for(k=1; k<=v; ++k)
        for(i=1; i<=v; ++i)
            for(j=1; j<=v; ++j)
                weight_mat[i][j] = min(weight_mat[i][j], weight_mat[i][k] + weight_mat[k][j]);
}

int main()
{
    int i, j, v1, v2, w;
    printf("Enter the number of vertices: ");
    scanf("%d", &v);
    printf("\nEnter the number of edges: ");
    scanf("%d", &e);

    for(i=1; i<=v; ++i){
        for(j=1; j<=v; ++j){
            if(i == j)
                weight_mat[i][j] = 0;
            else
                weight_mat[i][j] = 1000;
        }
    }

    printf("\nEnter %d edges: \n", e);
    for(i=1; i<=e; ++i){
        printf("Edge %d: ", i);
        scanf("%d %d", &v1, &v2);
        printf("Enter the weight of this edge: ");
        scanf("%d", &w);
        weight_mat[v1][v2] = w;
    }

    printf("\nWeight Matrix: \n");
    for(i=1; i<=v; ++i){
        for(j=1; j<=v; ++j)
            printf("%d\t", weight_mat[i][j]);
        printf("\n");
    }

    floyds();

    printf("\nAll pair shortest path weight matrix: \n");
    for(i=1; i<=v; ++i){
        for(j=1; j<=v; ++j)
            printf("%d\t", weight_mat[i][j]);
        printf("\n");
    }

    return 0;
}
