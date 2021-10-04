class Doubly{

  Node first,last,t;

  static class Node{
    
    int data;
    Node next;
    Node prev;
  }

  void create(int a[], int n){

    first  = new Node();
    first.data = a[0];

    first.next = null;
    first.prev = null;
    last = first;

    for(int i=1;i<n;i++){
      t = new Node();
      t.data = a[i];
      t.next = null;
      t.prev = last;
      last.next = t;
      last = t;

    }

  }

  int Length(Node p){
    int len=0;
    while(p!=null){
      len++;
      p = p.next;
    }

    return len;
  }

  void Insert(Node n, int index,int x){

    if(index <0 || index>Length(n))
      return;

    t = new Node();
    t.data = x;
    t.next = null;
    t.prev = null;
    if(index==0){

      if(n==null){
        first = t;

      }

      t.next = first;
      t.prev = null;
      first = t;



    }
    else{

      for(int i=0;i<index-1;i++){
        n = n.next;

      }

      t.next = n.next;
      n.next.prev = t;
      n.next = t;

    }

    
  }

  void Delete(Node n, int index){

    if(index<0 || index>Length(n))
      return;

    if(index == 0){
      // head
         first = first.next;
         if(first!=null){

        first.prev = null;
      }
    }
    else{

      for(int i=0;i<index-1;i++){

        n = n.next;
      }

      n.prev.next = n.next;
      if(n.next!=null){

        n.next.prev = n.prev;
      } 
      
    }
  }

  void Display(Node n){
    while(n!=null){
      System.out.print(n.data+" ");
      n = n.next;
    }
  }

  public static void main(String[] args){
    Doubly l = new Doubly();
    int a[] = {1,2,3,4};
    int n = a.length;
    l.create(a,n);

    //l.Insert(l.first,0,1);
    l.Delete(l.first,1);
    l.Display(l.first);
  }
}
