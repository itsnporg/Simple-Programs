class MergeLinked{
  Node first,second,third,last,t;

  static class Node{

    int data;
    Node next;

    Node(int d){
      data =d;
      next = null;
    }
  }

  void create(int a[], int n){

    first = new Node(a[0]);

    last = first;

    for(int i=1; i<n; i++){

      t = new Node(a[i]);

      last.next = t;
      last = t;
    }
  }

  void create2(int a[], int n){

    second = new Node(a[0]);
    last = second;

    for(int i = 1; i<n; ++i){
      t = new Node(a[i]);
      last.next = t;

      last = t;
    }
  }

  void merge(Node p, Node q){

    if(p.data < q.data){
      third = p;
      last = p;

      p = p.next;
      last.next = null;

    }

    else{
      third = q;
      third = q;

      q = q.next;
      last.next = null;
    }

    while(p!=null & q!=null){

      if(p.data<q.data){
        last.next = p;
        last = p;
        p = p.next;
        last.next = null;
      }
      else{
        last.next = q;
        last = q;
        q = q.next;
        last.next = null;
      }
    }
    if(p!=null){
      last.next = p;
    }
    if(q!=null){
      last.next = q;
    }
  }


  void Display(Node p){

    while(p!=null){
      System.out.print(p.data+" ");
      p = p.next;
    }
  }

  public static void main(String[] args){
    MergeLinked l = new MergeLinked();

    int a[] = {10,20,40,50,60};
    int a1[] = {15,18,25,30,35};

    l.create(a,a.length);

    l.create2(a1,a.length);

    l.merge(l.first,l.second);
    l.Display(l.first);
  }
}
