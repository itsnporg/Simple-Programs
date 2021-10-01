class Circular{
  Node first,last,t;
  // displaying 


  static class Node{
    int data;
    Node next;

    
  }

  void create(int a[], int n){

    first = new Node();
    first.data = a[0];
    first.next = first;
    last = first;

    for(int i=1; i<n; ++i){

      t = new Node();
      t.data = a[i];
      t.next = last.next;
      last.next = t;
      last = t;
    }
  }

  void display(Node p){

    if(p==null){
      return;
    }
    do{
      System.out.print(p.data+" ");
       p = p.next;
    }while(p!=first);
    
  }

  public static void main(String[] args){
    Circular l = new Circular();
    int a[] = {2,3,4,5,6};
    int n = a.length;

    l.create(a,n);
    l.display(l.first);
  }
}
