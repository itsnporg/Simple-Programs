class IsLoop{
  
  Node first,last,t;
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
      last = t;

    }
  }


  boolean isLoop(Node f){
    Node p=f,q=f;
    do{
      p = p.next;
      q = q.next;

      if(q!=null){
        q = q.next;
      }
      else{
        q = null;
      }
    }while(p!=null && q!=null && p!=q);

    if(p==q){
      return true;
    }
    else{
      return false;
    }

  }

  public static void main(String[] args){
    IsLoop l = new IsLoop();

    int a[] = {1,2,3,4,5};
    int n = a.length;

    l.create(a,n);
    l.first.next = l.first;
    System.out.println(l.isLoop(l.first));
  }

}
