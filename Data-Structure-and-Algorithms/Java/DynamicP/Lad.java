public class Lad{

  static int M[] = new int[10];

  static int solve(int n){

    if(n<=1){
      return n;
    }
    if(M[n]!=0){
      return M[n];
    }

    else{

      M[n] = solve(n-1)+solve(n-2);
    }

    return M[n];
  }

  public static void main(String[] args){

    int n = 5;
    solve(n);
    for(int i=0; i<n;i++){
      System.out.println(M[i]);
    }

     }
}
