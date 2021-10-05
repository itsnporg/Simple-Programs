class Loop{

 Node head;

 static class Node{
   int data;
   Node next;

   Node(int d){
     this.data =d;
     next = null;
   }
 }


 void push(int x){

   Node t = new Node(x);

   t.next = head;
   head = t;


 }

 void isLoop(Node f){
   Node p = f;
   Node q = f;

   do{
     p = p.next;
     q = q.next;

     if(q!=null){
       q = q.next;
     }
     else{
       q = null;
     }

   } while(p!=null && q!=null && p!=q);
     if(p==q){
       System.out.println("Loop detected");

     }
     else{
       System.out.println("Not a loop");
     }
   
 }


 public static void main(String[] args){

   Loop l = new Loop();
   l.push(4);
   l.push(5);
   l.push(6);
   l.push(7);
   l.head.next = l.head;

     l.isLoop(l.head);
 }

  
}
