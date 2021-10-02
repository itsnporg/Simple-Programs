class RemoveDup{
  static class Node{
    int data;
    Node next;

    Node(int d){

      this.data = d;

      next = null;
    }
  }

  Node first, last, t;

  
  void create(int a[], int n){

    first = new Node(a[0]);

    last = first;

    for(int i=1; i <n; ++i){

      t = new Node(a[i]);

      last.next = t;
      last = t;

    }
  }

  void remove(){
    Node p = first;
    Node q = p.next;

    while(q!=null){

      if(p.data!=q.data){

        p = q;

        q = q.next;
      }

      else{
        p.next = q.next;
        q = p.next;
      }
    }
  }

  void display(){
    Node p = first;

    while(p!=null){
      System.out.print(p.data+" ");

      p = p.next;
    }
  }

  public static void main(String  args[]){

    RemoveDup l = new RemoveDup();

    int a[] = {1,1,2,2,2,3,4};
    int n = a.length;

    l.create(a,n);
    l.remove();

    l.display();
  }
}
