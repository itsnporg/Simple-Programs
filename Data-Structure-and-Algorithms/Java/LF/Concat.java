class Concat{

  static Node first,second, last, t;

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
      last =t;
    }
  }
  void create1(int a[], int n){

    second = new Node(a[0]);
    last = second;

    for(int i=1;i<n;i++){
      t = new Node(a[i]);
      last.next = t;
      last =t;
    }
  }

  void Merge(Node first, Node second){
    // for the first Node 

    Node last;

    if(first.data < second.data){
      
      last = first;
      first = first.next;
      last.next  = null;

    }
    else{

      last = second;
      second = second.next;
      last.next = null;

    }

    // for connecting second node from the last.next 

    while(first!=null && second!=null){
      
      if(first.data<second.data){

        last.next = first;
        last = first;

        first = first.next;
        last.next = null;
      }

      else{

        last.next = second;

        last = second;
        second = second.next;
        last.next = null;
      }
    }

    // final step
    
    if(first!=null)
      last.next = first;
    else
      last.next = second;
  }

   void display(Node n){
    if(n!=null){

      System.out.print(n.data+" ");
      display(n.next);
    }
    else{
      return;
    }
  }

  boolean isSorted(Node p){
    int max = Integer.MIN_VALUE;

    
    while(p!=null){

      if(p.data<max){
        return false;
      }

      max =p.data;
      p = p.next;
      
    }
    return true;
  }


  public static void main(String[] args){

    Concat l = new Concat();
    int a[] = {2,1,10,15};

    int a1[] = {4,7,12,14};
    int n1 = a1.length;
    int n = a.length;

    l.create(a,n);
    l.create1(a1,n1);
    System.out.println(l.isSorted(l.first));
    l.display(l.first);
  }
}
