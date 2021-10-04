import java.io.*;
import java.util.*;
public class Priority{

  public static void main(String[] args) {
    PriorityQueue<Integer> q = new PriorityQueue<>(Collections.reverseOrder());
    int a[] = {14,53,13,52,52,1,356,9};


    for(int val:a){
      q.add(val);
    }

    while(q.size() > 0){
      System.out.println(q.peek());
      q.remove();
    }
    }
}
