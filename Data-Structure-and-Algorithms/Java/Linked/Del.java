class Del{
  Node first,last,t;

  static class Node{
    int data;
    Node next;

    Node(int d){
      this.data = d;
      this.next = null;
    }
  }


  void create(int a[], int n){

    first = new Node(a[0]);
    last  =first;

    for(int i=1; i <n; i++){

      t = new Node(a[i]);

      last.next = t;
      last =t;
    }
  }


  void print(){

    Node p = first;

    while(p!=null){
      System.out.print(p.data+" ");
      p = p.next;
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

  void Delete(Node n,int index){
    
    Node q = null;
    if(index<0 || index>Length(n)){
      return;
    }

    if(index==0){
      if(first==null){
        return;
      } 
      else{
        first = first.next;
      }
    }
    else{

      for(int i=0;i<index-1;i++){

        q = n;
        n = n.next;


      }
      q.next = n.next;
      q = n.next;
    }
    
  }

  boolean isSorted(Node n){
    int max = Integer.MIN_VALUE;

      while(n!=null){

        if(n.data<max){
          return false;
        }

        max = n.data;
        n = n.next;


      }

        return true;
    }
    

  void remDup(Node n){


    if(first==null){
      return;
    }

    else{


      Node q = n.next;

      while(q!=null){

        if(n.data!=q.data){
             n = q;
             q =q.next;

        }
        else{
          n.next = q.next;
          q = n.next;
        }
               
      }

      
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
    i--;
    while(q!=null){

      q.data = c[i];
      q = q.next;
      i--;
    }

  }

  void Re(Node p){
    Node q = null,r=null;

    while(p!=null){
      r = q;
      q = p;
      p = p.next;
      q.next = r;
    }
   first = q; 
  }


  void rl(Node q, Node p){

    if(p!=null){
      rl(p,p.next);
      p.next = q;
    }
    else{
      first = q;
    }

  }
  public static void main(String[] args){
   
    Del l = new Del();
    int a[] = {1 ,1,2,2,3,4,5};
    int n = a.length;
    l.create(a,n);
    l.Delete(l.first,5);
    l.remDup(l.first);
    l.rl(null,l.first);
    l.print();
  }
}

