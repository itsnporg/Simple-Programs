class Delete{

  Node first, last,t;

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
    int len = 0;

    while(n!=null){
      len++;
      n = n.next;
    }
    return len;
  }
  

  void Delete(Node n, int index){
    
    Node q=null;
    int x=-1;
    if(index<0 || index>Length(n)){
      return;
    }

    if(index ==1){

      first = first.next;
      
    }

    else{

      for(int i=2; i<=index; i++){

        q = n;
        n = n.next;
      }
          q.next = n.next;
          x = n.data;

      System.out.println(x);

      

      
    }
  }
  public static void main(String[] args){

    Delete l = new Delete();
    int a[] = {2,3,4,5};
    int n = a.length;
    l.create(a,n);
    l.Delete(l.first,2);
    l.Display(l.first);
  }
}
