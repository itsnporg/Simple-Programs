
class Insertion{
 static  Node head;

  static class Node{
    
    int data;
    Node next;

    Node(int d){
      data = d;
      next = null;
    }
  }

  // Insertion at the head 
  void push(Node n, int x){

    Node t = new Node(x);

    if(n==null){
      head=t;
    }
    else{
      t.next = head;
      head = t;
    }
  }

  void Append(Node n, int x){

    Node t = new Node(x);
    if(n==null){
     head = t; 
    }

    else{

      while(n.next!=null){
        n = n.next;
      }
      n.next = t;
      t = n;
    }
  }

  int Length(Node p){
    int len = 0;
    
    while(p!=null){
      len++;
      p = p.next;
    }
    return len;
  }

  void After(Node p, int index,int val){

    Node t = new Node(val);
    for(int i=1; i<Length(p); ++i){

      if(i==index){

        t.next = p.next;
        p.next =t;
        
      }
      p = p.next;
    }

  }

  void Disp(Node p)
  {
    if(p!=null){
      System.out.print(p.data+" ");
      Disp(p.next);
    }
  }

  public static void main(String[] args){
    Insertion l = new Insertion();
    l.push(head,3);
    l.push(head,5);
    l.Append(head,45);
    l.Append(head,34);
    l.After(head,2,54);
    l.Disp(head);
  }
}
