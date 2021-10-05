public class Ch{

  static int size = 7;
  // should be prime number 

  
  static class Node{
    int data;
    Node next;

    Node(int d){
      data = d;
      next = null;
    }
  }

  static Node chain[] = new Node[size];
 static void arr(){

    for(int i=0; i<size; i++){
      chain[i] = null;
    }
  }

  static void insert(int key){
   Node t = new Node(key);

   int index = key%size;
   if(chain[index]==null){
     chain[index] = t;
   }
   else{
     Node temp = chain[index];
     while(temp.next!=null){
       temp = temp.next;
     }
     temp.next = t;
   }
  }

  static void print(){
    for(int i=0;i<size;i++){
      Node temp = chain[i];
      System.out.print("Chain "+i+" -->");

      while(temp!=null){
        System.out.print(temp.data+" -->");
        temp = temp.next;
      }

    System.out.println("EMpty");
    }
  }

  public static void main(String[] args){
    arr();
    insert(4);
    insert(2);
    insert(5);
    insert(12);

    print();
  }
}
