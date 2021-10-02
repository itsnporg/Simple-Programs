import java.util.*;
public class Stk{

  public static void main(String[] args){

    Stack<String> st = new Stack<>();

    st.push("Apple");
    st.push("Mango");
    st.push("Litchi");

    // traverse
    //
    System.out.println(st.peek());
    st.pop();
    System.out.println(st);
    }
  }

