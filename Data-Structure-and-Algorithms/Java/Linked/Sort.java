class Sort{

  static Node first,last,t;

  class Node{
    int data;
    Node next;

    Node(int d){
      data = d;
      next = null;
    }
  }

  void create(int a[], int n)

  {
    first = new Node(a[0]);
    last = first;

    for(int i=1; i<n;i++){
      t = new Node(a[i]);
      last.next = t;
      last = t;
    }
  }

  void print(Node n){
    while(n!=null){
      System.out.print(n.data+" ");
      n = n.next;

    }
  }

  int Length(Node n){
    int len = 0;

    while(n!=null){
      len++;
      n = n.next;
    }
    return len;
  }
  void Insert(Node n, int x){
    Node q=null;
    Node t = new Node(x);

    if(first == null){
      first = t;
    }
    else{
    
    while(n!=null && n.data<x){
      q = n;
      n = n.next;
    }

    if(n==first){
      t.next = first;
      first = t;
    }
    else{

    t.next = q.next;
    q.next = t;

    

    
  
    }
  }

  }


  public static void main(String[] args)

  {
    Sort l = new Sort();
    int a[] = {10,20,30,40,50};
    int n = a.length;

    l.create(a,n);

    l.Insert(l.first,5);
    l.print(l.first);
  }

  
}

