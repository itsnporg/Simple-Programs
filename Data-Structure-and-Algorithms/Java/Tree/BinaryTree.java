import java.util.*;
class BinaryTree{

  static Node root;

  static class Node{
    int data;
    Node left;
    Node right;

    Node(int d){
      this.data = d;
      this.left = null;
      this.right= null;
    }
  }

  void create(){

    Node p, t;
    int x;

    Scanner sc  = new Scanner(System.in);

    Queue<Node> q = new LinkedList<>();

    System.out.println("Enter the root value");
    x = sc.nextInt();

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
      
      x = sc.nextInt();

      if(x!=-1){
        t = new Node(x);
        p.right = t;
        q.add(t);
      }
    }
  }


  void Pre(Node n){
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

  void In(Node n){

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

  int countNode(Node n){

    if(n!=null){
      return countNode(n.left)+countNode(n.right)+1;
    }

    return 0;
  }

  int Height(Node n){


    if(n==null){
      return 0;
    }
    int x  = Height(n.left);
    int y = Height(n.right);

    if(x>y){
      return x+1;
    }
    else{
      return y+1;
    }
  }

  void Level(Node n){
    Queue<Node> q = new LinkedList<>();

    System.out.print(n.data+" ");
    q.add(n);

    while(!q.isEmpty()){
      n = q.poll();
      if(n.left!=null){
        System.out.print(n.left.data+" ");
        q.add(n.left);
      }
      if(n.right!=null){
        System.out.print(n.right.data+" ");
        q.add(n.right);
      }
    }
  }

  public static void main(String[] args){
    BinaryTree l = new BinaryTree();
    l.create();
    l.Level(l.root);

    System.out.print("\n");
    System.out.println(l.countNode(l.root));
    System.out.println("\n");
    System.out.println(l.Height(l.root));

  }
  
}





















