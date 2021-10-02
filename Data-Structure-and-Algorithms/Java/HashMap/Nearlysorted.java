import java.io.*;
import java.util.*;

public class Nearlysorted{

  public static void main(String[] args) {
   Scanner sc = new Scanner(System.in);
	  int t = sc.nextInt();
	  
	  while(t-- >0){
	      PriorityQueue<Integer> q= new PriorityQueue<>();
	      int n = sc.nextInt();
	      int k = sc.nextInt();
	      
	      int a[] = new int[n];
	      
	      for(int i = 0; i <n; i++){
	          a[i] = sc.nextInt();
	      }
	      
	      for(int i = 0; i <k; i++){
	          
	          q.add(a[i]);
	      }
	      
	      for(int i =k; i <n; i++){
	          
	          System.out.print(q.remove()+" ");
	          q.add(a[i]);
	      }
	      while(q.size() >0){
	          System.out.print(q.remove()+" ");
	      }
	      
	      System.out.println();
	  }
    
  }
}
