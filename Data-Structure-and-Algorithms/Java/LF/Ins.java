
class Ins{

  static Node first, last,t;

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

  void Display(Node n){
    while(n!=null){
      System.out.print(n.data+" ");
      n = n.next;
    }
  }


  int Length(Node n){
    if(n!=null){
      return Length(n.next)+1;
    }
    else{
      return 0;
    }
  }

  void Insert(Node n, int index, int x){

    if(index<0 || index>Length(n)){
      return;
    }

    t = new Node(x);
    if(index==0){
      first = t;
    }
    else{

      for(int i=0;i<index-1;i++){
        n = n.next;
      }
      t.next = n.next;
      n.next = t;
    }
  }

  void Delete(Node p, int index){

    Node q = null;
    if(index<0 || index>Length(p)){
      return;
    }

    if(index==0){
      first = first.next;
    }

    else{

      for(int i=0;i<index-1;i++){

        q = p;
        p = p.next;
        
      }

      q.next = p.next;
      q = p.next;
    }
  }


  void RemDup(Node n){
    Node q = n.next;


    if(n==null){
      return;
    }

    
    while(q!=null && n.data!=q.data){
      n =q;
      q = q.next;
    }

    n.next = q.next;
    q = n.next;
  }

  void Rev(Node p){
    Node q = p;

    int a[] = new int[Length(p)];
    int i=0;

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


  void Revn(Node p){
    Node q =null,r = null;


    while(p!=null){
      r = q;
      q = p;
      p = p.next; 
      q.next = r;
     }

    
    first= q;

    
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
    Ins l = new Ins();
    int a[] = {1,2,2,2,5};
    int n = a.length;

    l.create(a,n);
    l.Insert(l.first,2,32);
    l.Display(l.first);
    System.out.println();
    l.Delete(l.first, 2);
    l.Display(l.first);
    System.out.println();
    l.Revn(l.first);
    l.Display(l.first);

  }
}
