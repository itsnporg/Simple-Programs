
class Remove{

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

  void RemoveM(Node p){
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

  void Display(Node n){
    while(n!=null){
      System.out.print(n.data+" ");
      n = n.next;
    }
  }
  


  public static void main(String[] args){
    Remove l = new Remove();
    int a[] = {1,1,2,2,3,4};
    int n = a.length;
    l.create(a,n);

    l.RemoveM(l.first);
    l.Display(l.first);

    

  }

}
