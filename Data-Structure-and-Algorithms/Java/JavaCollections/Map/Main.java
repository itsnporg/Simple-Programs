import java.util.*;
import java.lang.*;
import java.io.*;


public class Main{

  public static void main(String[] args){

    Scanner sc = new Scanner(System.in);

    int t = sc.nextInt();

    while(t-->0){
      int n =sc.nextInt();

      int a[] = new int[n];

      for(int i=0; i<n; i++){
        a[i] = sc.nextInt();
      }

      HashMap<Integer,Integer> h= new HashMap<>();

      for(int i=0; i<n; i++){
        if(h.containsKey(a[i])){
          h.put(a[i], h.get(a[i])+1);
        }
        else{
          h.put(a[i],1);
        }
      }

      long sum=0;
      for(int i=0; i<n; i++)
        sum+=n-h.get(a[i]);

      
      System.out.println(sum);
    }
  }
}
