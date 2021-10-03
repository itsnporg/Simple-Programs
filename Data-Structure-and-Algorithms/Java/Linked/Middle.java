class Middle{
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

    first  = new Node(a[0]);
    last = first;

    for(int i=1;i<n;i++){
      t = new Node(a[i]);
      last.next = t;
      last = t;
    }
  }

  void Display(){
   
    Node p = first;
    while(p!=null){
      System.out.print(p.data+" ");
      p =p.next;
    }
  }

  int Length(Node p){
    int len = 0;

    while(p!=null){
      len++;
      p = p.next;

    }

    return len/2;
  }

  void Search(Node p){

    int l = Length(p);
    while(l-->0){
      p = p.next;
    }
    System.out.println(p.data);

   }

  public static void main(String[] args){
    Middle l = new Middle();
    int a[] = {3,4};
    int n = a.length;

    l.create(a,n);
    l.Display();

    System.out.println();

    l.Search(l.first);
  }
}
