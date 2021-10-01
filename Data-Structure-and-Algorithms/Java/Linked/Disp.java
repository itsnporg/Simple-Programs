class Disp{

  Node first;
  Node last;
  Node t;
  static class Node{
    int data;
    Node next;

    Node(int d){
      this.data = d;
      this.next = null;
    }
  }



  void create(int a[], int n){

   first  = new Node(a[0]);

    last = first;

    for(int i=1; i<n;i++){

       t = new Node(a[i]);
      last.next = t;
      last =t;
    }
  }


  void Display(){

    Node p = first;

    while(p!=null){
      System.out.print(p.data+" ");
      p = p.next;
    }
  }

  public static void main(String[] args){

    Disp  l = new Disp();

    int a[] = {3,4,2,5,6};
    int n = a.length;
    l.create(a,n);
    l.Display();


  }

}
