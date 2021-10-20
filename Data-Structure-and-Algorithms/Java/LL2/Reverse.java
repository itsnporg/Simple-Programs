class Reverse{

  static Node first,last,t;

  static class Node{
    int data;
    Node next;

    Node(int d){
      data = d;
      next = null;
    }
  }

  void create(int a[], int n){

    first = new Node(a[0]);
    last = first;

    for(int i=1;i<n;++i){
      t = new Node(a[i]);
      last.next = t;
      last= t;
    }
  }

  void Reverse1(Node p){
    int a[] = new int[5];

    Node q = p;

    int i=0;
    while(q!=null){

      a[i] = q.data;
      q = q.next;
      i++; 
    }

    // move back to first one 
    q = p;
    i--;
    while(q!=null){
      q.data= a[i--];
      q = q.next;
    }
  }

  void Rever2(Node p){
    Node q =null,r=null;

    while(p!=null){
      r =q;
      q =p;
      p = p.next;
      q.next = r;
    }

    first = q;

    
  }

  void R3(Node q, Node p){
    if(p!=null){
      R3(p,p.next);
      p.next = q;
    }
    else{
      first =q;
    }
  }

    void Display(Node p){

    while(p!=null){
      System.out.print(p.data+" ");
      p = p.next;
    }
  }

  public static void main(String[] args){
    Reverse l = new Reverse();
    int a[] = {1,2,3,4,5};

    int n = a.length;

    l.create(a,n);
    l.R3(null,l.first);
    l.Display(first);
  } 
}
