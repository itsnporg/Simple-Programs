import java.util.*;

import jdk.internal.net.http.websocket.WebSocketRequest;

public class Priority{

  public static void main(String[] args){

    Queue<Integer> queue = new PriorityQueue<>();

    queue.offer(5);
    queue.offer(4);
    queue.offer(9);

    // traverse
    //

    // priority low to high
    System.out.println(queue);
    }
  }





