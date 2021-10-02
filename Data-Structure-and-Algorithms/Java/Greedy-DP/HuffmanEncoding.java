import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.Comparator;

// basic tree structure for huffman coding 
// Node class 

class HuffNode{
  int data;
  char c;

  HuffNode left;
  HuffNode right;
  
}

// comparator class 
// It compares the node 

class MyComparator implements Comparator<HuffNode>{
  public int compare(HuffNode x, HuffNode y){
    return x.data-y.data;
  }
}
public class HuffmanEncoding{
  
  // recursive function to print the nodes 

  public static void printCode(HuffNode root, String s){

    if(root.left==null && root.right==null && Character.isLetter(root.c)){
      System.out.println(root.c+":"+s);
      return;
    }
    printCode(root.left,s+"0");
    printCode(root.right,s+"1");

  }

  public static void main(String[] args){
    
    int n = 6;
    char charArray[] = {'a','b','c','d','e','f'};
    char frequency[] = {5,9,12,13,16,45};

    PriorityQueue<HuffNode> q = new PriorityQueue<HuffNode>(n, new MyComparator());
    
    for(int i=0;i<n;i++){
      HuffNode hn = new HuffNode();

      hn.c = charArray[i];
      hn.data = frequency[i];
      hn.right = null;

      q.add(hn);
    }

    // create a root node 
    HuffNode root = null;

    // now we extract the two minimum value 

    while(q.size() >1){
      HuffNode x = q.peek();
      q.poll();

      HuffNode y = q.peek();
      q.poll();


      HuffNode f  = new HuffNode();
      f.data = x.data+y.data;

      f.c = '-';
      
      f.left = x;
      f.right= y;
      root = f;
      q.add(f);
    }

    printCode(root,"");

  }

}
