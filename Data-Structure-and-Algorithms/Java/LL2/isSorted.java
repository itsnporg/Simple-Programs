class isSorted{

  Node first,last,t;

  static class Node{

    int data;
    Node next;

    Node(int d){
      data = d;
      next = null;
    }
  }


  void create(int a[],int n){

    first  = new Node(a[0]);
    last = first;


    for(int i = 1;i<n;i++){
      t = new Node(a[i]);

      last.next = t;

      last = t;
    }
  }


  boolean isSort(Node n){
    int max = Integer.MIN_VALUE;

    while(n!=null){

      if(n.data<max){
        return false;
      }
        max =n.data;
        n = n.next;
      
    }
    return true;
  }

  public static void main(String[] args){
    isSorted l = new isSorted();
    int a[] = {1,2,3,4,2,6};
    int n = a.length;

    l.create(a,n);

    System.out.println(l.isSort(l.first));
  }
}
