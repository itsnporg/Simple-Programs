// Insertion Operation

class LLOperat{

  static class Node{

    int data;
    Node next;

    // constructor

    Node(int d){
      this.data = d;
      next = null;
    }
  }

  Node head;


  // Insert at the beginnig 

  void push(int x){

    Node t = new Node(x);

    t.next = head;
    head = t;
  }

  void append(int x){
    

    Node p=head;
    Node t = new Node(x);
    if(head==null){

      head = new Node(x);

    }

    while(p.next!=null){

      p = p.next;
    }
    p.next = t;
  }

  void after(Node n, int x){
    Node t = new Node(x);

    if(n==null){
      return;
    }
    
      t.next = n.next;
      n.next = t;
    
  }

  void Display(){

    Node p = head;

    while(p!=null){
      System.out.print(p.data+" ");
      p = p.next;
    }
  }

  public static void main(String[] args){
    LLOperat l = new LLOperat();
    l.push(5);
    l.push(3);
    l.append(6);
    l.after(l.head.next,89);

    l.Display();
  }
}
