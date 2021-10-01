#include <stdio.h>

int main(){
    int n,m;
    int a[n][m], b[n][m], result[n][m];
    printf("Enter number of rows and column you want to enter : ");
    scanf("%d,%d",&n,&m);

printf("Enter 1st matrix\n"); //INPUT FOR A[N][M]
for (int i = 0; i < n; ++i)
{
    for (int j = 0; j < m; ++j)
    {
        printf("Enter a[%d][%d]: ", i + 1, j + 1);
        scanf("%d", &a[i][j]);
    }
}

printf("Enter 2nd matrix\n"); // INPUT FOR B[N][M]
for (int i = 0; i < n; ++i){
    for (int j = 0; j < m; ++j)
    {
        printf("Enter b[%d][%d]: ", i+1, j+1);
        scanf("%d", &b[i][j]);
    }
}

for (int i = 0; i < n; ++i){   //ADDITION
    for (int j = 0; j < m; ++j)
    {
        result[i][j] = a[i][j] + b[i][j];
    }
}

printf("\nAddition Of 2 nxm Matrix : \n");    //SUM

for (int i = 0; i < n; ++i){
    for (int j = 0; j < m; ++j)
    {
        printf("%d\t", result[i][j]);
    }
        printf("\n");
    }
return 0;
}