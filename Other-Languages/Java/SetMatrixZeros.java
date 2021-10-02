import java.io.*;
import java.util.*;

class SetMatrixZeroes {
    public void setMatrixZeroes(int[][] matrix) {

        int row = matrix.length;
        int col = matrix[0].length;

        int[] rowZero = new int[row];
        int[] colZero = new int[col];

        for(int i=0;i<row;i++) {
            for(int j=0;j<col;j++) {
                if(matrix[i][j]==0) {
                    rowZero[i]=1;
                    colZero[j]=1;
                }
            }
        }
        for(int i=0;i<row;i++) {
            for(int j=0;j<col;j++) {
                if(rowZero[i]==1 || colZero[j] == 1) {
                    matrix[i][j] =0;
                }
            }
        }
        


        

    }
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int n = in.nextInt();
        int m = in.nextInt();

        int[][] matrix = new int[n][m];

        for(int i = 0 ; i < n ; ++i) {
            for(int j = 0 ; j < m ; ++j) {
                matrix[i][j] = in.nextInt();
            }
        }

        in.close();
        new SetMatrixZeroes().setMatrixZeroes(matrix);

        for(int i = 0 ; i < n ; ++i) {
            for(int j = 0 ; j < m ; ++j) {
                System.out.print(matrix[i][j]);
                System.out.print(' ');
            }
            System.out.println();
        }
    }
}