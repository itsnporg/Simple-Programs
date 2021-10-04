import java.util.*;
public class Parenthesis{
  
  static boolean isPara(String s){

    Deque<Character> st = new ArrayDeque<Character>();

    for(int i=0; i<s.length(); i++){
      char x = s.charAt(i);

      if(x=='(' || x=='{' || x=='['){
        st.push(x);
         continue;
      }


     
      if(st.isEmpty()){
        return false;


      }
       char ch;

      switch(x){

        case ')':
          ch = st.pop();
          if(ch=='{' || ch == '[')
            return false;
          break;
        case '}':
          ch = st.pop();
          if(ch=='(' || ch=='[')
            return false;
          break;
        case ']':
          ch = st.pop();
          if(ch=='(' || ch=='{')
            return false;
          break;
      }
    }
    return (st.isEmpty());

  }
  public static void main(String[] args){

    String s = "{{ad(ad)}}";
    System.out.println(isPara(s));

  }
}
