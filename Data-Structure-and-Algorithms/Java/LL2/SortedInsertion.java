class SortedInsertion{
  
  Node first,last,t;

  static class Node{
    
    int data;
    Node next;
    
    // constructor 

    Node(int d){
      data = d;
      next = null;
    }
  }
  
  void create(int a[], int n){

    first = new Node(a[0]);
    last = first;

    for(int i=1; i<n;i++){

      t = new Node(a[i]);
      last.next = t;
      last = t;

    }
  }


  void Display(Node n){
    if(n!=null){
      System.out.print(n.data+" ");
      Display(n.next);
    }
  }
  void Sorted(Node p, int x){

    Node q = null;

    t = new Node(x);

    if(first == null){
      first = t;
    }

    else{

      while(p!=null && p.data<x){
        q = p;
        p = p.next;
      }

      if(p == first){
        t.next = first;
        first = t;

      }
      else{
        q.next = t.next;
        q.next = t;
      }
    }
  }
  public static void main(String[] args){

    SortedInsertion l = new SortedInsertion();
    int a[] = {10,20,30,40,50,60};
    int n = a.length;

    l.create(a,n);
    l.Sorted(l.first,0);
    l.Display(l.first);
  }

  
  
}
