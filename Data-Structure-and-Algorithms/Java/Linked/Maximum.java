class Maximum{

  Node first,last,t;

  static class Node {
    int data;
    Node next;

    Node(int d){
      this.data = d;
      this.next = null;
    }
  }

  void create(int a[], int n){

    first = new Node(a[0]);

    last = first;

    for(int i=1; i <n; i++){

      t = new Node(a[i]);
      last.next = t;
      last = t;
    }
  }
  // maximum 
  void maximum(){

    int u = Integer.MIN_VALUE;
    Node k = first;
    while(k!=null){

      u = Math.max(u,k.data);

      k = k.next;
      
    }

    System.out.println("Maximum element is "+u);
  }

  void display(){

    Node p  = first;

    while(p!=null){

      System.out.print(p.data+" ");
      
      p = p.next;
    }
    System.out.println("\n");
}

public static void main(String[] args){

  Maximum l = new Maximum();
  int a[] = {3,4,5,6,1};
  int n = a.length;

  l.create(a,n);
  l.display();
  
  l.maximum();
}

}
