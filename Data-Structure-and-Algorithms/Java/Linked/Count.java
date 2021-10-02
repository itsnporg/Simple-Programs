public class Count {

  Node first,last,t;
  static class Node{
    int data;
    Node next;

    Node(int d){
      this.data= d;
      this.next = null;
    }
  }

  void create(int a[], int n){

    first = new Node(a[0]);
    last = first;

    for(int i=1; i <n; i++){

      t = new Node(a[i]);
      last.next = t;

      last =t;
    }
  }


  void count(){
    int c=0;

    Node p = first;

    while(p!=null){
      c++;
      p = p.next;
    }
    System.out.println(c);
  }

  public static void main(String[] args){

    Count l = new Count();
    int a[] = {3,4,5,6};
    int n = a.length;

    l.create(a,n);
    l.count();

  }
}
