
class SinglyCreate{

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

    for(int i = 1; i <n; i++){

      t = new Node(a[i]);

      last.next = t;
      last = t;
    }
  }


  void Display(Node p){

    while(p!=null){

      System.out.print(p.data+" ");

      p = p.next;
    }
  }

  void RDisplay(Node p){

    if(p!=null){
      System.out.print(p.data+" ");
      RDisplay(p.next);
      
  }
}

  public static void main(String[] args){

    SinglyCreate l = new SinglyCreate();
    
    int a[] = {1,2,3,4,5};
    int n = a.length;
    l.create(a,n);
    l.RDisplay(l.first);
  }
}
