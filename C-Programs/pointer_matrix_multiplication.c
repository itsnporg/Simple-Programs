#include <stdio.h>

#define ROW 3
#define COL 3

void input(int mat[][COL]);
void print(int mat[][COL]);
void multiply(int mat1[][COL], int mat2[][COL], int res[][COL]);


void main()
{
    int mat1[ROW][COL];
    int mat2[ROW][COL];
    int product[ROW][COL];

    //input
    printf("Enter elements in first matrix of size %dx%d\n", ROW, COL);
    input(mat1);

    printf("Enter elements in second matrix of size %dx%d\n", ROW, COL);
    input(mat2);


    //function_call_multiply
    multiply(mat1, mat2, product);


    //function_call_print
    printf("Product of both matrices is : \n");
    print(product);
}

//input function
void input(int mat[][COL])
{
    int row, col;

    for (row = 0; row < ROW; row++)
    {
        for (col = 0; col < COL; col++)
        {
            scanf("%d", (*(mat + row) + col));
        }
    }
}

//print function
void print(int mat[][COL])
{
    int row, col;

    for (row = 0; row < ROW; row++)
    {
        for (col = 0; col < COL; col++)
        {
            printf("%d ", *(*(mat + row) + col));
        }

        printf("\n");
    }
}

//multiply_function
void multiply(int mat1[][COL], int mat2[][COL], int res[][COL])
{
    int row, col, i;
    int sum;


    for (row = 0; row < ROW; row++)
    {
        for (col = 0; col < COL; col++)
        {
            sum = 0;

            for (i = 0; i < COL; i++)
            {
                sum += (*(*(mat1 + row) + i)) * (*(*(mat2 + i) + col));
            }
            //store_result_of_product
            *(*(res + row) + col) = sum;
        }
    }
}