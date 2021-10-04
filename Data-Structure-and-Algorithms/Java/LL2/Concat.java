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

  void create1(int a[], int n){

    first = new Node(a[0]);
    last = first;

    for(int i=1;i<n;i++){
      t = new Node(a[i]);

      last.next = t;
      last = t;
    }
  }
void create2(int a[], int n){

    second = new Node(a[0]);
    last = second;

    for(int i=1;i<n;i++){
      t = new Node(a[i]);

      last.next = t;
      last = t;
    }
  }

void concat(Node p, Node q){

  if(p.next==null)
    p.next = q;
  

  else
    concat(p.next,q);
  
}

void Display(Node n){
  while(n!=null){
    System.out.print(n.data+" ");
    n = n.next;
  }
}

public static void main(String[] args){

 Concat l = new Concat();
 int a[] = {1,2,3,4};
 int a1[] = {5,6,7,8};

 l.create1(a,a.length);
 l.create2(a1,a1.length);

 l.concat(l.first,l.second);
 l.Display(l.first);
}

}
