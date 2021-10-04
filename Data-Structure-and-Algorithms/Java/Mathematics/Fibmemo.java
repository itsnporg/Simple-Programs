import java.util.*;
public class Fibmemo{
  
  static int fib(int n){

    int dp[] = new int[n+2];

    Arrays.fill(dp,-1);
    dp[0] = 0;
    dp[1] = 1;


    if(n<=1)
      return n;

    if(dp[n]!=-1){
      return dp[n];
    }

    else{
      dp[n] = fib(n-1)+fib(n-2);
    }

    return dp[n];

    
  }

  public static void main(String[] args){

    System.out.println(fib(10));
  }
}
