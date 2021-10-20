import java.util.*;
class BT{
  Node root;
  static class Node{
    int data;
    Node left;
    Node right;

    Node(int d){
      data = d;
      left = null;
      right = null;
    }
  }

  void create(){
    Node t;
    Node p;
    int x;
    Scanner sc = new Scanner(System.in);
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
  

  void preOr(Node n){
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

  void Inor(Node n){
    Stack<Node> st = new Stack<>();
    while(n!=null || !st.isEmpty()){
      if(n!=null){
        st.push(n);
        n = n.left;
      }
      else{
        n=st.pop();
        System.out.print(n.data+" ");
        n = n.right;
      }

    }
  }

  int Height(Node n){
    int x=0,y=0;
    if(n==null){
      return 0;
    }
      x = Height(n.left);
      y = Height(n.right);



    if(x>y){
      return((x+1));
    }
    else{
      return((y+1));
    }
  }

  int N(Node n){
    if(n!=null){
      return N(n.left)+N(n.right)+1;
    }
    return 0;
  }

  public static void main(String[] args){
    BT l = new BT();
    l.create();
    l.preOr(l.root);
    System.out.println("\n");
    l.Inor(l.root);

    System.out.println(" "+l.Height(l.root));
    System.out.println(" "+l.N(l.root));
  }
}
