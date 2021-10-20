import java.util.*;
public class Post{

  static int eval(String s){

    Stack<Integer> st = new Stack<>();

    for(int i=0;i<s.length();i++){

      char c = s.charAt(i);

      if(Character.isDigit(c))
        st.push(c-'0');

      else{


        int val1 = st.pop();
        int val2 = st.pop();

        switch(c){

          case '+':
            st.push(val1+val2);
            break;
          case '-':
            st.push(val2-val1);
            break;
          case '/':
            st.push(val2/val1);
            break;
          case '*':
            st.push(val2*val1);
            break;

        }
      }
    }
    return st.pop();
  }

  public static void main(String[] args){
    String s = "35*62/+4-";
    System.out.println("Evaluated: "+eval(s));
    
  }
}
