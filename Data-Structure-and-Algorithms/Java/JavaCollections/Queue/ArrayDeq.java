import java.util.*;

public class ArrayDeq{

  public static void main(String[] args){

    ArrayDeque<String> queue = new ArrayDeque<>();

    queue.offer("Apple");
    queue.offerFirst("Mango");
    queue.offer("Litchi");
    queue.offerLast("Pop");

    // traverse
    //

    
    System.out.println(queue);

    System.out.println(queue.peekFirst());

    System.out.println(queue.pollLast());

    System.out.println(queue);
    }
  }





