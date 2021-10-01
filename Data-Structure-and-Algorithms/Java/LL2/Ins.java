// This program is suitable for position based insertion
// position starts from 1
// if it was index based then , we should start index from zero
// Aurthor
//
// @Nishant Banjade

class Ins{

Node first, last,t;
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

    for(int i=1; i<n; i++){

      t = new Node(a[i]);
      last.next = t;
      last = t;
      
    }

  }


  void Display(Node n){

    while(n!=null){
      System.out.print(n.data+" ");
      n = n.next;
    }
  }

  int Length(Node p){
    int len=0;
    while(p!=null){
      len++;
      p = p.next;
    }


    return len;
  }
 
  void Insert(Node n, int index, int x){

    if(index<=0 || index>Length(n)){
      return;
    }


    if(index == 1){
      t = new Node(x);

      
      t.next = first;
      first = t;
    }
    else{

      t = new Node(x);
      for(int i=2; i<=index;i++){
        n = n.next;
      }
      t.next = n.next;
      n.next = t;
    }
  }

  public static void main(String[] args){
    Ins l = new Ins();
    int a[] = {1,2,3,4};
    int n = a.length;

    l.create(a,n);
    l.Insert(l.first,0,34);
    l.Display(l.first);
  }
}
