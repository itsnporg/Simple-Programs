class BST{
  static Node root;

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

  // Iterative insert
 

  void Insert(int x){

    Node t = root;
    Node p;
    Node r = null;

    if(root==null){
      p = new Node(x);
      root = p;
      return;
    }

    while(t!=null){
      r = t;
      if(x<t.data){
         t= t.left;
      }
      else if(x>t.data){
        t = t.right;
      }
      else{
        return;
      }
    }

    p = new Node(x);

    if(p.data<r.data){
      r.left = p;
    }
    else{
      r.right = p;
    }

  }
  boolean search(int x){
    Node t = root;

    while(t!=null){
      if(x==t.data){
        return true;
      }
      else if(x<t.data){
        t = t.left;
      }
      else{
        t = t.right;
      }
    }
    return false;
  }
void Inorder(Node n){
  if(n!=null){
    System.out.print(n.data+" ");
    Inorder(n.left);
    Inorder(n.right);
  }
}
public static void main(String[] args){
  BST l = new BST();
  l.Insert(4);
  l.Insert(5);
  l.Insert(2);

  l.Inorder(l.root);

  System.out.println(l.search(15));
}

}


