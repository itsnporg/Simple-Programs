class Insert{
  Node first,last,t;

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

    for(int i=1; i<n;i++){
      t = new Node(a[i]);
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
  /*
  void Insert(Node n,int index, int x){
    
    if(index<=0 || index>Length(n)){
      return;
    }

      t = new Node(x);
    if(index==1){
      t.next = first;
      first = t;

    }
    else{

      for(int i=2;i<index;i++){
        n = n.next;
      }
      t.next = n.next;
      n.next = t;


    }



  
  }
  */

  void SortedInsert(Node n, int x){
    Node q = null;

    t = new Node(x);
    if(first == null){
      first = t;
    }

    else{
    while(n!=null && n.data < x){
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
/*
  void Delete(Node n, int index){
    int x = -1;
    Node q = null;
    if(index<0 || index>Length(n)){
      return; 
    }

    if(index==0){
      x = first.data;
      first =first.next;
      System.out.println(x);
      
    }

    else{

      for(int i=1;i<index;i++){
        q = n;
        n = n.next;
      }
      q.next = n.next;

      
    }
  }
*/

  /*
  boolean isSor(Node n){
    int min = -5353;

    while(n!=null){

      if(n.data<min){
        return false;
      }

        min = n.data;
        n = n.next;
    }
    return true;
  
  }
  */

  void Remove(Node p){
    Node q = p.next;

    
    while(q!=null){

      if(p.data!=q.data){
        p = q;
        q = q.next;
      }
      else{
        p.next = q.next;
        q = p.next;
      }
      
    }
  }
  void Reverse(Node p){
    int a[] = new int[Length(p)];
    int i=0;

    Node q = p;

    while(q!=null){
      a[i] = q.data;
      q = q.next;
      i++;
    }
    i--;

    q = p;

    while(q!=null){
      q.data = a[i--];
      q = q.next;
    }
  }
  void Displa(Node n){
    while(n!=null){
      System.out.print(n.data+" ");
      n = n.next;
    }
  }

  public static void main(String[] args){
    Insert l = new Insert();
    int a[] = {10,10,30,40,50};
    int n = a.length;

    l.create(a,n);
   // l.SortedInsert(l.first,15);
   // l.Delete(l.first,2);
   //l.Remove(l.first);
    l.Reverse(l.first);
    l.Displa(l.first);
    //System.out.println(l.isSor(l.first));
  }

}
