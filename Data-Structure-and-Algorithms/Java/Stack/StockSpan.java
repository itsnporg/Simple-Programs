import java.util.*;
import java.io.*;
public class StockSpan{

  static void solve(int a[], int n){

    int span[] = new int[n];
    Stack<Integer> st = new Stack<>();
    st.push(0);

    for(int i = 1; i <n; i++){

      while(st.size() > 0 && a[i] > a[st.peek()]){
        st.pop();
      }

      if(st.size()==0){
        span[i] = i+1;
      }
      else{
        span[i] = i-st.peek();
      }
      st.push(i);
    }

    for(int i = 1; i <n; i++){
      System.out.print(span[i]+" ");
    }
  }
  public static void main(String[] args) {
   int a[] = {100,80,60,70,60,75,85};
   int n = a.length;
   solve(a,n);
  }
}
