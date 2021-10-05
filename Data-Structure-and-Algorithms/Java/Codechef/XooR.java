import java.util.*;

public class XooR{

  public static void main(String[] args){
    
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int k = sc.nextInt();

    int a[] = new int [n];
    int sum[] = new int[33];

    for(int i = 0; i<n;i++){
      a[i] = sc.nextInt();
    }

   
    for(int i=0;i<n;i++){
      int x = a[i];
      int j = 32;

      while(x>0){
        
        sum[j]+= x%2;
        j--;
        x  = x/2;
      }
    }

    int res = 0;

    for(int i=0; i<33;i++){

      if(sum[i]%2==0){
        res+=sum[i]/2;
      }
      else{
        res+=1+sum[i]/2;
      }
    }

    System.out.println(res);


    
    
  }
}
