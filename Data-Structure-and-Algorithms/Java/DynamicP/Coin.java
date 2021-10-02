public class Coin{

  public static void main(String[] args){

    int n = 18;
    int a[] = {7,5,1};

    System.out.println(minCoins(n,a));

  }

  // n = 18   a[] = [ 1 5 7 ]
  static int minCoins(int n, int a[]){

    if(n==0) return 0;

    int ans = Integer.MAX_VALUE;
    for(int i=0; i<a.length; i++){

      if(n-a[i] >=0){

        int sub = minCoins(n-a[i], a);

        if(sub!=Integer.MAX_VALUE && sub+1 < ans){
          ans = sub+1;
        }
      }
  }

  return ans;
  }
}
