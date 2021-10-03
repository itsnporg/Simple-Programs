class Cir{

  Node first,last,t;

  static class Node{
    int data;
    Node next;

  }

  void create(int a[], int n){
    first = new Node();
    first.data =a[0];
    first.next = first;
    last = first;

    for(int i=1;i<n;i++){
      t = new Node();
      t.data  = a[i];

      t.next = last.next;
      last.next = t;
      last = t;


    }
  }
  int Length(Node p){

    int len = 0;

    do{
      len++;
      p = p.next;
    }while(p!=first);

    return len;
  }


  void Insert(Node p, int index, int x){

    if(index<0 || index >Length(p))
      return;

    t = new Node();
    t.data = x;
    t.next = t;
    if(index==0){

      if(first==null){
        first = t;
        first.next = first;
      }
      else{

        while(p.next!=first){

          p.next = t;
          t.next = first;
          first = t;

        }
      }

    }
      else{

        for(int i=0;i<index-1;i++){
          p = p.next;
        }

        t.next = p.next;
        p.next = t;
      }
    
  }

  void Delete(Node p,int index){
    Node q;

    if(index<0 || index >Length(p)){
      return;
    }

      if(index==1){

        
        while(p.next!=first){

          p = p.next;

        }

        if(first==p){
          first = null;
          
        }

        else{
        
          p.next = first.next;
          first = p.next;
    }}
    

    else{

      for(int i=0;i<index-1;i++){
        p = p.next;
      }
      q = p.next;

      p.next = q.next;
      
    }
  }
  
  void Display(Node n){

    do{
      System.out.print(n.data+" ");
      n = n.next;
    }while(n!=first);
  }

  public static void main(String[] args){
    Cir l = new Cir();
    int a[] = {1,2,3,4};
    int n = a.length;

    l.create(a,n);
    l.Insert(l.first,3,23);
    l.Display(l.first);
    System.out.println();
    l.Delete(l.first,0);
    l.Display(l.first);
    
  }
}
