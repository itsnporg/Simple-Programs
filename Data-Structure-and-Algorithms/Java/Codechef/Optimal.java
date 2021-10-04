import java.util.*;
public class Optimal{

  static int size = Integer.MAX_VALUE;
  static long gcd(long a, long b){
    if(b==0){
      return a;
    }
    return gcd(b, (a%b));
  }

  public static void main(String[] args) throws java.lang.Exception{

    Scanner sc = new Scanner(System.in);
    
   int t = sc.nextInt();
    while(t-->0){

      long n = sc.nextLong();
      long sum = 0;

      long a[] = new long [(int)n+1];
     for(long i=0; i<n;i++){
        a[(int)i] = sc.nextLong();

      }



      long pre[] = new long [(int)n+1];
      long suf[] = new long [(int)n+1];
      long h[] = new long [(int)n+1];
      for(long i=0; i<n; i++){
        sum+=a[(int)i];
      }

      if(a.length==1){
        System.out.println("1");
        continue;
      }
      
      pre[0] = a[0];
      for(long i=1; i<n; i++){
        pre[(int)i] = gcd(pre[(int)i-1],a[(int)i]);
      }

      // suffix
      suf[(int)n-1] = a[(int)n-1];
      for(long i = n-2; i>=0; i--){
        suf[(int)i] =gcd(suf[(int)i+1],a[(int)i]); 
      }

      h[0] = suf[1];
      h[(int)n-1] = pre[(int)n-2];

      for(long i=1;i<n-1;i++){
        h[(int)i] = gcd(pre[(int)i-1],suf[(int)i+1]);
      }

      
      long ans = Long.MAX_VALUE;
      long s = 0;

      for(long i = 0; i<n; i++){

        s  =((sum-a[(int)i])/h[(int)i])+1;
        ans = Math.min(ans,s);
        }
      System.out.println(ans);








    }
  }
}
