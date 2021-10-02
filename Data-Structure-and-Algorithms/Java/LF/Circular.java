
class Circular{

  Node first,last,t;

  static class Node{

    int data;
    Node next;

  }

  void create(int a[], int n){
    
    first  = new Node();
    first.data = a[0];
    first.next = first;
    last = first;
    
    for(int i=1;i<n;i++){
      
      t = new Node();
      t.data = a[i];
      t.next = last.next;

      last.next = t;
      last = t;
    }

    
  }

  int Length(Node n){
    int len= 0;
    do{
      len++;
      n = n.next;
    }while(n!=first);

    return len;
  }
  void Insert(Node n, int index,int x){

    if(index<0 || index>Length(n)){
      return;
    }
      t =  new Node();
      t.data = x;
      t.next = t;


      
    if(index == 0){
     
        if(first == null){
        first = t;
        first.next = first;
      }

      else{

        while(n.next!=first){
          
          n = n.next;
        }

          n.next = t;
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

  void Delete(Node p, int index){
    Node q;
    int x;

    if(index<0 || index>Length(p)){
      return;
    }

    if(index ==1){

      while(p.next!=first){
        p = p.next;
      }
      x = first.data;
      if(p==first){
        first = null;
      }
      else{
        p.next = first.next;
        first = p.next;
      }
    }
    else{

      for(int i=0;i<index-2;++i){
        p = p.next;

      }
      q = p.next;
      p.next =q.next;
      x = q.data;
    }
  }
  void Display(Node n){
    do{
      System.out.print(n.data+" ");
      n = n.next;
    }while(n!=first);
  }
  public static void main(String[] args){
    Circular l = new Circular();
    int a[]={1,2,3,4};
    int n = a.length;
    l.create(a,n);
    l.Insert(l.first,4,32);
    l.Delete(l.first,2);
    l.Display(l.first);
  }

}








