class Delete{

  Node first, last, t;
  static class Node{
    int data;
    Node next;

    Node(int d){

      this.data = d;
      next = null;
    }
  }

  void create(int a[], int n){

    first = new Node(a[0]);
    last = first;

    for(int i=1; i <n;i++){

      t = new Node(a[i]);
      last.next = t;

      last = t;
    }


  }

  void del(int x){

    Node temp = first;
    Node prev = null;

    if(temp!=null && temp.data == x){
      // head to be deleted

      first = temp.next;
      return;
    }

    // if not , search 

    while(temp!=null && temp.data!=x){

      prev = temp;
      temp = temp.next;
    }
    if(temp==null){
      return; 
    }
    prev.next = temp.next;

    
  }

  void display(){

    Node p = first;

    while(p!=null){
      System.out.print(p.data+" ");
      p = p.next;
    }
  }

  public static void main(String[] args){
    Delete l = new Delete();
    int a[] = {5,3,1,6,4};
    int n = a.length;

    l.create(a,n);
    l.del(3);

    l.display();
  }
}
