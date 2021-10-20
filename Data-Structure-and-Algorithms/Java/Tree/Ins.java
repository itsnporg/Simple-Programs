class Ins{

  static Node root;

  static class Node{

    int data;
    Node left;
    Node right;

    // constructor 
    Node(int d){
      data = d;
      left = null;
      right = null;

    }
  }

  static void Insertion(int key){
    Node n = root;
    Node r = null;

    Node p = new Node(key);
    if(root==null){

      root = p;
      return;
    }
    else{
      while(n!=null){
        r = n;

        if(key<n.data){
          n = n.left;
        }
        else if(key>n.data){
          n = n.right;
        }
        else{
          return;
        }
      }
      if(p.data<r.data){
        r.left = p;
      }
      else{
        r.right = p;
      }
    }
  }

  static Node Rinsert(Node n,int key){
    Node t = null;

    if(n==null){
      t = new Node(key);
      return t;
    }
    if(key<n.data){
     n.left =  Rinsert(n.left,key);
    }
    else if(key>n.data){
      n.right = Rinsert(n.right,key);
    }
    return n;

  }

  static void pre(Node n){
    if(n!=null){
      System.out.print(n.data+" ");
      pre(n.left);
      pre(n.right);
    }
  }

  public static void main(String[] args){
    Ins l = new Ins();
    root = Rinsert(root, 42);
    Rinsert(root, 3);
    Rinsert(root, 4);
    Rinsert(root, 8);
       pre(root);
    
  }
}
