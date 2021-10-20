class Search{
  Node first, last, t;

  static class Node{
    int data;
    Node next;

    Node(int d){
      data =d;
      next =null;
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

  void Display(Node p){
    if(p!=null){
      System.out.print(p.data+" ");
      Display(p.next);
    }
  }

  void Search(Node p, int x){
    
    while(p!=null){
      if(p.data == x){
        System.out.println("\n"+x+" is Found");
        break;
      }
      p = p.next;
    }
  }

  int Recur(Node p, int x){

    if(p.data!=x){
      
     return Recur(p.next,x);

    }
    return p.data;

  }
  // search based on the index 

  int Length(Node p){
    int len =0;

    while(p!=null){
      len++;
      p =p.next;
    }

    return len;
  }

  void Sind(Node p, int index){

    for(int i=1; i <=Length(p);i++){
      if(i==index){

        System.out.println(p.data+" is in "+index+" index");
        break;
      }

      p = p.next;
    }
  }

  public static void main(String[] args){
    Search l = new Search();

    int a[] = {1,3,3,4,5};

    int n = a.length;
    
    l.create(a,n);
    l.Display(l.first);
    l.Search(l.first,3);
    System.out.println(l.Recur(l.first,4));
    System.out.println();
    l.Sind(l.first,4);
  }
}
