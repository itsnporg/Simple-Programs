import java.io.*;
import java.util.*;

public class Kth{
  public static void main(String[] args) {
    
    int a[] = {4,5,2,1,3,12,11};
    int n = a.length;

    int k = 3;

    PriorityQueue<Integer> q = new PriorityQueue<>();

    for(int i = 0; i <n; i++){

      if(i < k){

        q.add(a[i]);
      }
      else{

        if(a[i] > q.peek()){
          q.remove();
          q.add(a[i]);
        }
      }
    }

    while(!q.isEmpty()){
      System.out.print(q.remove()+" ");
    }
  }
}
