import java.util.*;
class Infix{

  static int pred(char ch){

    switch(ch){
      case '+':
      case '-':
        return 1;
      case '*':
      case '/':
        return 2;
      case '^':
        return 3;
        
    }
    return -1;
  }


  static String infx(String str){
    String result = "";

    Stack<Character> st = new Stack<>();
    
    for(int i=0;i<str.length();i++){
      char c = str.charAt(i);

      if(Character.isLetterOrDigit(c))
        result+=c;
      else if(c=='(')
        st.push(c);

      else if(c==')'){

        while(!st.isEmpty() && st.peek()!='(')
          result+=st.pop();
          st.pop();

        }
      else{
        while(!st.isEmpty() && pred(c) <= pred(st.peek())){

          result+=st.pop();
        }
      
      st.push(c);
      
  }

  
}
while(!st.isEmpty()){
  if(st.peek()=='(')
    return "INV";
  result+=st.pop();
}

return result;

}

public static void main(String[] args){

    String str = "a+b*(c^d-e)^(f+g*h)-i";

    System.out.println(infx(str));
  }
}

