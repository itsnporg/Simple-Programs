class stackLL{

  static Node top;

  static class Node{
    int data;
    Node next;

  }

  stackLL(){
    this.top = null;
  }

  void push(int x){

    Node temp = new Node();
    if(temp==null){
      System.out.println("Overflow");
      return;
    }

    temp.data = x;
    temp.next = top;
    top = temp;

    System.out.println(x+" is pushed");
    }

  int pop(){
    Node temp = top;

    int x = -1;
    if(temp==null){
        return -1;
    }
    else{
      x = temp.data;
      
      top = top.next;

    }
    return x;

  }

  void print(){
    Node temp = top;
    if(top==null){
      return;
    }
    while(temp!=null){
      System.out.print(temp.data+" ");
      temp = temp.next;
    }
  }

    
  int peek(){

    if(top==null){
      return -1;
    }
    else{
      return top.data;
    }
  }
  

  public static void main(String[] args)
  {
    stackLL st = new stackLL();

    st.push(5);
    st.push(4);
    st.push(3);
    st.push(2);
    st.push(1);
    st.pop();
    st.print();
    System.out.println("\n"+st.peek());
  }
}
