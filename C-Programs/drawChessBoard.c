void drawChessBoard()
{
    printf("this is a function for drawing the chess board \n");

    int temp = 1;
    int highest = 9;
    for (int i = 0; i < 8; i++)
    {
        for (int j = temp; j < highest; j++)
        {
            if (j % 2 == 0)
            {
                printf(" B ");
            }
            else
            {
                printf(" W ");
            }
        }
        if (temp == 1 && highest == 9)
        {
            temp = 0;
            highest = 8;
        }
        else
        {
            temp = 1;
            highest = 9;
        }

        printf("\n");
    }
    printf("\n");
}
int main()
{
    drawChessBoard();
}
