#include <stdio.h>
#include <stdlib.h>

int adj_mat[20][20], ET[20][3], VT[20], V_VT[20], v, e, x=0;

void initialize(){
    int i;
    for(i=1; i<=v; ++i){
        VT[i] = 0;          // Vt will be null initially
        V_VT[i] = 1;        // V-Vt will be V
    }
    VT[1] = 1;              // Considering the source as vertex 1 so initializing Vt by vertex 1
    V_VT[1] = 0;            // Removing vertex one from V-Vt
}

void Prim(){
    int i, j, k, min, v1, v2;
    initialize();

    for(i=1; i<v; ++i){     // <v because one vertex has already been added to VT. Also the algo expands a tree by exactly one vertex on each of its iterations, the total number of such iterations is v-1
        min = INT_MAX;
        for(j=1; j<=v; ++j){        // To find the minimum-weight edge
            for(k=1; k<=v; ++k){
                if(VT[j]!=0 && V_VT[k]!=0 && adj_mat[j][k] < min){
                    min = adj_mat[j][k];
                    v1 = j;
                    v2 = k;
                }
            }
        }
        ET[x][0] = v1;
        ET[x][1] = v2;
        ET[x][2] = min;
        x++;

        VT[v2] = 1;
        V_VT[v2] = 0;
    }
}

int main()
{
    int i, j, v1, v2, w;

    printf("How many vertices do you want to enter: ");
    scanf("%d", &v);

    printf("\nHow many edges do you want to enter: ");
    scanf("%d", &e);

    for(i=1; i<=v; ++i){                        // Representing the graph as weight matrix
        for(j=1; j<=v; ++j){
            if(i == j)
                adj_mat[i][j] = 0;              // Edge from a vertex to itself isn't there so weight initialized as 0
            else
                adj_mat[i][j] = INT_MAX;        // weight initialized as INT_MAX = infinite for vertices that don't have edge between them
        }
    }

    printf("\nEnter %d edges:\n", e);
    for(i=1; i<=e; ++i){
        printf("Enter edge %d: ", i);
        scanf("%d %d", &v1, &v2);
        printf("Enter the edge weight: ");
        scanf("%d", &w);
        adj_mat[v1][v2] = adj_mat[v2][v1] = w;
    }

    Prim();

    int total_weight = 0;
    printf("\nEdges in the minimum spanning tree obtained from Prim's Algorithm: \n");
    for(i=0; i<x; ++i){
        printf("%d --> %d  (Edge Weight = %d)\n", ET[i][0], ET[i][1], ET[i][2]);
        total_weight += ET[i][2];
    }
    printf("\nThe total weight of the minimum spanning tree obtained = %d\n\n", total_weight);

    return 0;
}
