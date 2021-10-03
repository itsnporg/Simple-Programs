class Concat{

  Node first, last, second;
  Node t;

  static class Node{
    int data;
    Node next;

    Node(int d){
      this.data = d;
      next = null;
    }
  }

  void create(int a[], int n){

    first = new Node(a[0]);
    last = first;

    for(int i =1; i<n; i++){
      t = new Node(a[i]);
      last.next = t;
      last = t;
    }
  }

  void create1(int a[], int n){

    second = new Node(a[0]);

    last = second;

    for(int i=1; i<n;++i){

      t = new Node(a[i]);
      last.next = t;
      last = t;

    }

  }

  void merge(Node p, Node q){
    
    if (p.next == null)
        p.next = q;
    else
        merge(p.next,q);
  }

  void display(Node p){

    
    while(p!=null){
      System.out.print(p.data+" ");
      p = p.next;
    }
  }

  public static void main(String[] args){
    Concat l = new Concat();
    int a[] = {2,3,4,5};
    int a1[] = {4,5,6,7};

    l.create(a,a.length);
    
    l.create1(a1,a1.length);


    l.merge(l.first,l.second);
    l.display(l.first);
  }
}

