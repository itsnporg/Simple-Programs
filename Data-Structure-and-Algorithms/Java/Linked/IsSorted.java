class IsSorted{

  Node first, last, t;

  static class Node{
    int data;
    Node next;

    // constructor

    Node(int d){
      this.data = d;

      next = null;
    }
  }

  void create(int a[], int n){

    first = new Node(a[0]);
    last = first;

    for(int i=1; i<n;++i){
      t = new Node(a[i]);
      last.next = t;
      last = t;
    }
  }


  int isSort(){
    int x = Integer.MIN_VALUE;
    Node p = first;

    while(p!=null){

      if(p.data<x){
        return 0;
      }
      x = p.data;
      p = p.next;
    }
    return 1;

  }
  void Display(Node n){
    if(n!=null){


      System.out.print(n.data+" ");
      Display(n.next);
    }
  }

  public static void main(String[] args){

    IsSorted l = new IsSorted();
    int a[] = {1,2,3};
    l.create(a,a.length);
    l.Display(l.first);
    System.out.println();
    System.out.println(l.isSort());
  }
}
