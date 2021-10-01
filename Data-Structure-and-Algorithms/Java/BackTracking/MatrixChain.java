public class MatrixChain{

  static int MatrixOrder(int p[], int n)
  {
    int m[][] = new int[n][n];
    int s[][] = new int[n][n];


    int i, j, k, d, q;
    int min;

    // for cost , M[1][1] M[2][2] M[3][3]

    for (i = 1; i < n; i++)
      m[i][i] = 0;

    for(i = 1; i <n; i++)
      s[i][i] = 0;

    for(d = 1; d<n-1; d++){

      for(i = 1; i<n-d; i++){

        j = i+d;
        
        min = Integer.MAX_VALUE;

        for(k = i; k<=j-1; k++){

          //q means cost 

          q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];


          if(q<min)
            min = q;
            s[i][j] =k;
        }
        m[i][j] = min;
      }
    }


    return m[1][n-1];
  }

  public static void main(String[] args){

    int a[] = new int[] {1,2,3,4};
    int size = a.length;

    System.out.println(MatrixOrder(a,size));
  }
}
