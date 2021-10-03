// Implementation of the queue data structure 

public class Queue{

  static int Max = 100;
  
  int a[] = new int[Max];
  static int front = -1;// for deletion
  static int rear  = -1; // for insertion 


  boolean isEmpty(){
    if(front==rear){
      return true;
    }
    return false;
  }

  boolean isFull(){
    if(rear==Max-1){
      return true;
    }
    return false;
  }

  void enqueue(int x){

    if(isFull()){
      System.out.println("Queue overflow !!");
    }
    else{
      rear++;

      a[rear] = x;
      System.out.println(a[rear]+" Enqueued");
    }

    
  }


  void dequeue(){

    if(isEmpty()){
      System.out.println("Queue underflow !!");
    }
    else{
    front++;

    int x = a[front];
    System.out.println(x+" Dequeued");
  }

  
  }
  void print(){

    if(isEmpty()){
      return;
    }

    for(int i=front+1;i<=rear;i++){
      System.out.print(a[i]+" ");
    }
  }

  public static void main(String[] args){
    Queue q = new Queue();
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    q.dequeue();

    q.dequeue();
    q.print();
  }
}
