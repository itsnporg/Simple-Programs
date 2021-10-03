import java.util.*;
class Tree{
  
  static Node root;

  static class Node{

    int data;
    Node left;
    Node right;

    Node(int d){
      data = d;

      this.left = null;
      this.right = null;

    }
  }

  void create(){
    int x;
    Node p,t;

    Scanner sc = new Scanner(System.in);

    System.out.println("Enter the root value");

    x = sc.nextInt();
    Queue<Node> q = new LinkedList<Node>();



    root = new Node(x);
    q.add(root);


    while(!q.isEmpty()){

      p = q.poll();
      System.out.println("Enter the left child of "+p.data);

      x = sc.nextInt();

      if(x!=-1){

        t = new Node(x);
        p.left = t;
        q.add(t);

      }

      System.out.println("Enter the right child of "+p.data);

      x  = sc.nextInt();
      if(x!=-1){

        t = new Node(x);

        p.right = t;

        q.add(t);
      }
    }


  }
  

  void Preorder(Node n){

    Stack<Node> st = new Stack<>();

    while(n!=null || !st.isEmpty()){

      if(n!=null){

        System.out.print(n.data+" ");
        st.push(n);
        n = n.left;
      }

      else{
        n = st.pop();
        n = n.right;
      }
    }
  }

  void Inorder(Node n){

    Stack<Node> st = new Stack<>();

    while(n!=null || !st.isEmpty()){
      if(n!=null){

        st.push(n);
        n = n.left;

      }
      else{
        n = st.pop();
        System.out.print(n.data+" ");
        n = n.right;
      }
    }

  }

  void PostOrder(Node n){

    Stack<Node> st  = new Stack<>();

    while(n!=null || !st.isEmpty()){

      if(n!=null){
        st.push(n);
        n = n.left;
        
      }

      else{
        n = st.pop();
        n = n.right;
        System.out.println(n.data+" ");
      }

      
  }
  }

  public static void main(String[] args){
    Tree l  = new Tree();

    l.create();
    l.Preorder(l.root);
    System.out.println("\n");
    l.Inorder(l.root);
    System.out.println("\n");
   // l.PostOrder(l.root);
  }
}
