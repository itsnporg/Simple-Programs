import java.util.Scanner;
import java.util.PriorityQueue;

public class Optimal{
  
  static int minComp(int size, int files[]){
    
    PriorityQueue<Integer> pq = new PriorityQueue<>();

    for(int i=0;i<size;i++){
      pq.add(files[i]);

    }

    int count  = 0;

    while(pq.size()>1){
      int temp = pq.poll()+pq.poll();

      count+=temp;

      pq.add(temp);

    }
    return count;
  }

  public static void main(String[] args){
    int size = 5;

    int files[] = new int[] {30,30,20,10,5};
    System.out.println("Minimum Computation "+minComp(size,files));
  }
}
