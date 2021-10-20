class Search{
  Node first, last, t;

  static class Node{

    int data;
    Node next;

    // constructor 

    Node(int d){

      this.data =d;
      this.next = null;
    }
  }


  void create(int a[], int n){

    first = new Node(a[0]);

    last = first;

    for(int i=1; i <n; ++i){
      t = new Node(a[i]);



      last.next = t;
      last = t;
    }
  }

  void Display(){
    Node p = first;

    while(p!=null){
      System.out.print(p.data+" ");

      p = p.next;
    }
  }

  // done 

  void search(Node o, int x){
    int flag = 0;
    while(o!=null){

      if(o.data==x){

        flag=1;
        break;
      }
      else{
       flag = 0;
       
      }
      o =o.next;
    }
    if(flag==1){

        System.out.println("Element "+o.data+" is found");
    }
    else{

        System.out.println("Element is not found");
    }
  }

  void  Recursive(Node p, int x){

    if(p==null){
      return;

    }

    if(p.data == x){
      System.out.println(x+" Found");
    }

    else{
      Recursive(p.next,x);
    }
  }

  public static void main(String[] args){
    Search l = new Search();

    int a[] = {3,4,5,62,3,4,6};
    int n = a.length;

    l.create(a,n);
    l.search(l.first,62);
    l.search(l.first, 56);
    l.Recursive(l.first,4);
    l.Display();

  }
}
