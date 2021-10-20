public class LCSMemoization{


  int lcs(char x[], char y[] , int i, int j, int m[][])
  {
    int N = x.length;
    int M = y.length;
    if(i==N || j==M)
      return 0;

    if(m[i][j] != -1)
      return m[i][j];

    
    if(x[i] == y[j])
    {

      m[i][j] = lcs(x,y,i+1,j+1,m)+1;

    }

    else
      
      m[i][j] = max(lcs(x,y,i+1,j,m), lcs(x,y,i,j+1,m));

    
    return m[i][j];


  
  }


  int max(int a,int b){
    return (a>b)?a:b;

  }

  public static void main(String[] args){

    LCSMemoization l = new LCSMemoization();
    String s1 = "one";
    String s2 = "longest";


    
    int m[][] = new int[101][101];
    char x[] = s1.toCharArray();
    char y[] = s2.toCharArray();

    //System.out.println(x.length);
    //System.out.println(y.length);

    int m1 = s1.length();
    int n = s2.length();

    for(int i=0; i<100;i++){
      for(int j=0;j <100; j++){
        m[i][j] = -1;
      }
    }

    int k = l.lcs(x,y,0,0,m);
    System.out.println(k);
    
  }
}
