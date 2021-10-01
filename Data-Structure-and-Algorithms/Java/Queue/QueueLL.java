// Queue implementation using the linkedlist representation

class QueueLL{

  static Node front = null,rear = null;

  static class Node{
    int data;
    Node next;

  }

   void enqueue(int x){
    
     Node temp = new Node();

     if(temp == null){
       System.out.println("Overflow");

     }
     else{

       temp.data = x;
       temp.next = null;

       if(front==null){
         front = temp;
         rear = temp;
       }
       else{
         rear.next = temp;
         rear= temp;
       }

     }
  }

  void dequeue(){

    
    Node temp;
    if(front == null){
      System.out.println("underflow!");
    }
    else{
      int x = front.data;
      temp = front;
      front = front.next;

      System.out.println(x+" Dequeued!");
    }
  }

  void Display(){
    Node n = front;
    while(n!=null){
      System.out.print(n.data+" ");
      n = n.next;
    }
  }

  public static void main(String[] args){

    QueueLL q = new QueueLL();
    q.enqueue(4);
    q.enqueue(3);
    q.enqueue(5);
    q.enqueue(6);
    q.dequeue();
    q.Display();
  }


}
