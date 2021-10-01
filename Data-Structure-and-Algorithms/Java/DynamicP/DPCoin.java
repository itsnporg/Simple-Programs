import java.util.Arrays;
class DPCoin{
  
  static int myc(int n, int a[], int dp[]){

    if(n==0) return 0;

    int ans = Integer.MAX_VALUE;

    for(int i=0; i<a.length; i++){

      if(n-a[i] >=0){

        int sub = 0;

        if(dp[n-a[i]]!=-1){
          sub = dp[n-a[i]];
        }
        else{
          sub = myc(n-a[i],a,dp);
        }

        if(sub != Integer.MAX_VALUE && sub+1<ans){
          ans = sub+1;
        }
      }
    }

    return dp[n] = ans;

  }

  public static void main(String[] args){

    int n = 18;

    int a[] = {7,5,1};
    int dp[] = new int[n+1];

    Arrays.fill(dp,-1);

    dp[0] = 0;

    int ans = myc(n,a,dp);

    System.out.println(ans);
  }
}
