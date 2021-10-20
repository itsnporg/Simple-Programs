class DoublyInsertion{

  Node first,last,t;

  static class Node{
    int data;
    Node next;
    Node prev;
   
  }

  void create(int a[],int n){
    
     first = new Node();
     first.data = a[0];
     first.prev = null;
     first.next = null;
     last = first;

    for(int i=1; i<n; i++){

      t = new Node();
      t.data = a[i];
      t.next = last.next;
      t.prev = last;
      last.next = t;
      last = t;
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

  void Insert(Node p, int index, int x){
    Node t;

    if(index <0 || index>Length(p))
      return;

    if(index==0){
      //head condition
      t = new Node();
      t.data = x;
      t.prev = null;
      t.next = first;
      first.prev = t;
      first = t;
    }
    else{

      for(int i=0;i<index-1;i++){
        p = p.next;
      }

      t = new Node();
      t.data = x;
      t.prev = p;
      t.next = p.next;
      if(p.next!=null){
        p.next.prev = t;
      }
      p.next = t;
    }
  }
  
  int Delete(Node p, int index){
    int x = -1;

    if(index<1 || index>Length(p)){
      return -1;
    }

    if(index ==1){
      first = first.next;
      if(first!=null)
        first.prev = null;

      x = p.data;
      
    }
    else{
      for(int i=0; i<index-1;i++){

        p = p.next;
      }
      p.prev.next = p.next;
      if(p.next!=null)
        p.next.prev = p.prev;
      x = p.data;
    }

    return x;





  }

  void Reverse(Node p){
    Node temp;

    while(p!=null){
      temp = p.next;
      p.next = p.prev;
      p.prev = temp;
      p = p.prev;

      if(p!=null && p.next==null){
        first = p;
      }
    }
  }
  void Display(Node p){
    while(p!=null){
      System.out.print(p.data+" ");
      p = p.next;
    }
  }
 

 public static void main(String[] args){
    DoublyInsertion l = new DoublyInsertion();
    int a[] = {3,4,5,6};
    int n = a.length;

    l.create(a,n);
    l.Insert(l.first,2,43);
    l.Delete(l.first, 2);
    l.Display(l.first);
    l.Reverse(l.first);
    System.out.println();
    l.Display(l.first);
  }

}
