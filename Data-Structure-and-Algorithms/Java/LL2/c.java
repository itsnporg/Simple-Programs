class c{

  static Node first, last, t;

  class Node{
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

    for(int i=1; i<n; i++){
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

  void max(Node n){
    int max = Integer.MIN_VALUE;

    while(n!=null){
      if(n.data>max){
        max = n.data;
      }
      n = n.next;
    }

    System.out.println("\n"+max);
  }

  void SearchMe(Node n, int x){

    int f =0;
    while(n!=null){
      if(n.data == x){
        f = 1;
        break;
      }
      else{
        f = 0;
        
      }
      n = n.next;
    }

    if(f==1){
      System.out.println("Found element "+x);

    }
    else{
      System.out.println("Not found");
    }
  }

  public static void main(String[] args){

    c l = new c();
    int a[] = {1,2,3,4,5,6,7};
    int n = a.length;
    l.create(a,n);
    l.print(l.first);
    l.max(l.first);
    l.SearchMe(l.first,5);
    
}
}
