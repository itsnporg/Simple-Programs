class Sum{
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


  void summ(){

    Node p = first;

    int s=0;
    while(p!=null){
      s+=p.data;
      p = p.next;
    }

    System.out.println(s);
  }

  public static void main(String[] args){
    Sum l = new Sum();
    int a[] = {1,2,3,4,5};
    int n = a.length;
    l.create(a,n);
    l.summ();
  }
}
