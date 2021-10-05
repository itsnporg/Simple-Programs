
class Prac{

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

    for(int i=1;i<n;i++){
      t = new Node(a[i]);
      last.next = t;
      last = t;
    }
  }
  
  // Insert 
  int Length(Node n){
    int l = 0;
    while(n!=null){
      l++;
      n = n.next;
    }
    return l;
  }
  void Insert(Node n, int index, int x){
    Node t = new Node(x);
    if(index<0 || index > Length(n))
      return;
    if(index==0){
      if(first == null){
        first = t;
      }
      else{
        t.next = first;
        first = t;
      }
    }
    else{
      for(int i=0;i<index-1;i++){
        n = n.next;
      }
      t.next = n.next;
      n.next = t;
    }
  }

  void Delete(Node n, int index){
    Node q=null;
    if(index<0 || index>Length(n)){
      return;
    }

    if(index==0){
      if(n==first){
        first = first.next;
      }
    }
    else{
      for(int i=0;i<index-1;i++){
       q = n;
       n = n.next;
      }

      q.next = n.next;
    }
  }
  
  void Sorted(Node n, int x){
    Node t = new Node(x);

    Node q = null;
    if(first==null){

      first= t;
    }
    else{

      while(n!=null && n.data<x){
        q = n;
        n = n.next;
      }

      if(n==first){
        t.next = first;
        first =t;
      }
      else{
        t.next = q.next;
        q.next = t;
      }
    }
  }

  boolean isSot(Node n){

    int m = Integer.MIN_VALUE;

    while(n!=null){

      if(n.data<m){
        return false;
      }
      else{

        m = n.data;
        n =n.next;
      }
    }
    return true;
  }

  void Display(Node n){
    while(n!=null){
      System.out.print(n.data+" ");
      n = n.next;
    }
  }

  void Rem(Node p){
    Node q = p.next;

    while(q!=null){

      if(p.data!=q.data){
      
        p = q;
        q= p.next;
      }
      else{
        p.next = q.next;
        q = p.next;
      }
    }

  }

  // Reverse using sliding pointers 
  void Reverse(Node p){

     Node q =null,r =null;
     while(p!=null){
       r = q;
       q = p;
       p =p.next;
       q.next = r;
       first = q;
     }

  }

  void Rev(Node p){

    int c[] = new int[Length(p)];

    Node q = p;
    int i=0;

    while(q!=null){
      c[i] = q.data;
      q = q.next;
      i++;
    }

    q = p;
    i--; // because, i gets incrementedd for one more time 
   
    while(q!=null){
      q.data = c[i--];
      q = q.next;
    }
  }

  void Rv(Node q, Node p){
    if(p!=null){
      Rv(p,p.next);
      p.next = q;
    }
    else{
      first = q;
    }
  }
  public static void main(String[] args){

    Prac l = new Prac();
    int a[] = {10,10 ,30,30,40,50,60};
    int n = a.length;
    l.create(a,n);

    System.out.println(l.isSot(l.first));
    l.Sorted(l.first,15);
    l.Rv(null,l.first);
    l.Display(l.first);

  }
}
