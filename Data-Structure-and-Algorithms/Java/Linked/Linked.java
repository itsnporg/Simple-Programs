class Linked{

  Node head;

  static class Node{
    int data;
    Node next;

    Node(int d)
    {
      this.data = d;

      this.next = null;
    }
  }

  void traverse(){

    Node n = head; 

    while(n!=null){
      System.out.print(n.data+" ");
      n = n.next;
    }
  }

  public static void main(String[] args){
    Linked l = new Linked();

    l.head = new Node(4);
    Node s = new Node(5);

    l.head.next = s;

    l.traverse();

  }
}

