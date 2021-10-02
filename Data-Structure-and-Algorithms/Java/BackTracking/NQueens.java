public class NQueens{
  
  static final int N = 4;

  static void print(int board[][]){

    for(int i=0; i<N; i++){

      for(int j=0;j<N; j++){

        System.out.print(board[i][j]+" ");
      }

      System.out.println();

    }
  }

  // isSafe or not ;
  // from left to right 

static   boolean isSafe(int board[][], int row, int col){
    // row on the left side 

    int i, j;
    for(i=0; i<col; i++){
      if(board[row][i]==1)
        return false;
    }
    
    // upper diagonal 

    for( i=row,j=col; i>=0 && j>=0; i--, j--)
      if(board[i][j]==1)
        return false;

    // lower diagonal

    for(i=row,j=col; j>=0 && i<N; i++,j--){
      if(board[i][j]==1)
        return false;

    }
    return true;

  }

  static boolean solve(int board[][], int col){
    if(col>=N)
      return true;

    for(int i=0; i<N; i++){
      if(isSafe(board,i,col)){
        board[i][col] = 1;

        if(solve(board,col+1)==true)
          return true;

        board[i][col] = 0;

      }
    }
    return false;
  }

  public static void main(String[] args){
 int board[][] = { { 0, 0, 0, 0 },
                          { 0, 0, 0, 0 },
                          { 0, 0, 0, 0 },
                          { 0, 0, 0, 0 } };
  
        if (solve(board, 0) == false) {
            System.out.print("Solution does not exist");
        }
  
        print(board);
  }

}
