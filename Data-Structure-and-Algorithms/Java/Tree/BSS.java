class BSS{

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

  Node RInsert(Node p, int key){

    Node t = null;

    if(p==null){
      t = new Node(key);
      return t;
    }

    if(key <p.data){
      p.left = RInsert(p.left,key);
    }
    else if(key>p.data){

      p.right = RInsert(p.right,key);
    }
      return p;


  }

  // Height , if pred or succ have more height then take it and replace it with the node to be deleted

  int Height(Node n){
    int x,y;

    if(n==null){
      return 0;
    }

    x = Height(n.left);
    y = Height(n.right);

    if(x>y)
    {
      return x+1;
    }
    else
    {
      return y+1;
    }
  }
  
  Node InPre(Node p){
    while(p!=null && p.right!=null){
      p = p.right;
    }
    return p;
  }

  Node InS(Node p){
    while(p!=null && p.left!=null){
      p=p.left;

    }
    return p;
  }


  Node Delete(Node p, int key){

    Node q;

    // if root is null. retrurn

    if(p==null){
      return null;
    }

    if(p.left==null && p.right==null){
      if(p==root){
        root = null;

      }
      return null;
    }

    if(key<p.data){
      p.left = Delete(p.left,key);
    }
    else if(key>p.data){

      p.right = Delete(p.right,key);
    }

   // if both are equal with eachother 
    else{

      if(Height(p.left)>Height(p.right)){

        q = InPre(p.left);
        p.data = q.data;
        p.left = Delete(p.left,q.data);// delete q 
      }
      else{
        q  = InS(p.right);
        p.data = q.data;
        p.right = Delete(p.right,q.data);
      }
    }

    return p;
  }

  void Pre(Node n){
    if(n!=null){
      System.out.print(n.data+" ");
      Pre(n.left);
      Pre(n.right);
    }
  }

  public static void main(String[] args){
    BSS l = new BSS();
    root = l.RInsert(root,32);
    l.RInsert(l.root,3);
    l.RInsert(l.root,6);    
    l.RInsert(l.root,5);
    
    l.Pre(l.root);
    System.out.println("\n");
    l.Delete(l.root,3);
    l.Pre(l.root);
  }
}
