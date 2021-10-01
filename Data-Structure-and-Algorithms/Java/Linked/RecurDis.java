class RecurDis{

  static Node head;

  static class Node{

    int data;
    Node next;
  }

  void create(int a[], int n){

    Node last,t;
    head = new Node();
    head.data = a[0];
    head.next = head;
    last = head;

    for(int i=1;i<n;i++){

      t = new Node();
      t.data = a[i];
      t.next  = last.next;

      last.next =t;
      last = t;

    }
  }

  static int f = 0;
  void Rdisplay(Node n){

       if(n!=head || f==0){
         f = 1;
         System.out.print(n.data+" ");
         Rdisplay(n.next);
       }
       f = 0;
  }

  public static void main(String[] args){
   RecurDis l = new RecurDis(); 
   int a[] = {3,4,5,6,7};
   int n = a.length;

   l.create(a,n);
   l.Rdisplay(l.head);

  }
}
