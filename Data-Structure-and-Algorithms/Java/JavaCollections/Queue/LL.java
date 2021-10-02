import java.util.*;

public class LL{

  public static void main(String[] args){

    Queue<String> queue = new LinkedList<>();

    queue.offer("Apple");
    queue.offer("Mango");
    queue.offer("Litchi");

    // traverse
    //

    System.out.println(queue.peek());
    System.out.println(queue.poll());
    
    System.out.println(queue);
    }
  }




