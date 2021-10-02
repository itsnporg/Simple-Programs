class DLL{

  Node first,last,t;
  static class Node {

    int data;
    Node next;

    // constructor 

    Node(int d){
      this.data = d;
      this.next = null;
    }

  }

  void Create(int a[], int n){

    first = new Node(a[0]);

    last = first;

    for(int i=1;i <n; i++){

      t = new Node(a[i]);

      last.next = t;
      last =t ;
    }


  }


  void Display(){

    Node p = first;
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
    
    DLL l = new DLL();
    int a[] = {4,5,2,4,5,6,7,8,4,3,2,3,4,6,7,8,3,2,4,5,7};
    int n = a.length;
    l.Create(a,n);
    l.Display();
    System.out.println();
    l.RDisplay(l.first);


  }
}
