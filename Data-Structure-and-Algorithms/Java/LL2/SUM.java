class SUM{

  Node first, last, t;

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
    last =first;

    for(int i=1; i<n; i++){
      t = new Node(a[i]);

      last.next =t;
      last =t ;
    }
  }

  void Display(Node p){
    
    if(p!=null){
      System.out.print(p.data+" ");
      Display(p.next);

    }
  }

  int countNode(Node p){
    int sum = 0;

    while(p!=null){
      sum++;
      p = p.next;
    }

    return sum;

    
  }

  int Max(Node p){
    int max = Integer.MIN_VALUE;

    while(p!=null){

      if(p.data>max){
        max = p.data;
      }
      p = p.next;
    }

    return max;
  }

  int sumM(Node p){

    int s=0;

    while(p!=null){
      s+=p.data;
      p = p.next;
    }

    return s;
  }

  public static void main(String[] args){
    SUM  l = new SUM();
    int a[] = {1,2,3,4,5};
    l.create(a,a.length);

    l.Display(l.first);


    System.out.println();
    System.out.println(l.countNode(l.first));
    System.out.println();
    System.out.println(l.Max(l.first));
    System.out.println();
    System.out.println(l.sumM(l.first));
  }
  
}
