public class LCSRecursion{

  int lcs(char x[], char y[], int i, int j)
  {
    int N = x.length;
    int M = y.length;
    if(i==N || j==M)
    {
      return 0;
    }

    if(x[i] == y[j])
    {
      return (lcs(x,y,i+1,j+1)+1);

    }
    else{
      return max(lcs(x,y,i+1,j),lcs(x,y,i,j+1));
    }
  }

  int max(int a, int b){
    return (a>b)?a:b;
  }

  public static void main(String[] args){

    LCSRecursion lcs = new LCSRecursion();
    String s1 = "Longest";
    String s2 = "one";

    char x[] = s1.toCharArray();
    char y[] = s2.toCharArray();
    
    System.out.println(lcs.lcs(x,y,0,0));
  }
}
