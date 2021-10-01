import java.util.*;

public class Queen{

  private static int N;

  private static int[][] board = new int[100][100];

  private static boolean isAttack(int i, int j){

    int k,l;

    // check if there is queen in row or column 

    for(k = 0; k<N;k++)
    {

      if(board[i][k]==1 || board[k][j] == 1)
        return true;

    }

    // check for diagonal 

    for(k = 0; k<N; k++){

      for(l = 0; l<N; l++){
        if((k+l)==(i+j) || (k-l)==(i-j))
        {
          if(board[k][l]==1)
            return true;
        }
      }
    }

    return false;
  }

  private static boolean nqueen(int n){

    int i, j;

    if(n==0)
      return true;

    for(i=0;i<N;i++){
      for(j=0;j<N;j++){

        if(!isAttack(i,j) && board[i][j]!=1){
          board[i][j] = 1;

          if(nqueen(n-1)==true)
          {

            return true;
          }

          board[i][j] = 0;
        }
      }
    }
    return false;
  }

  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    N = sc.nextInt();

    int i, j;

    nqueen(N);

    for(i=0;i<N;i++){
      for(j=0; j<N; j++)
        System.out.print(board[i][j]+"\t");

      System.out.print("\n");
    }
  }
}
