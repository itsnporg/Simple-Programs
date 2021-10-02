import java.util.*;
import java.io.*;
public class Celebrity{
static int solve(int a[][], int n)
    {
    	// code here 
    
    Stack<Integer> st = new Stack<>();
    for(int i =0; i <a.length; i++){
      st.push(i);
    }
    while(st.size() >=2){
      int i = st.pop(); // 4
      int j = st.pop(); // 3
      if(a[i][j] == 1){
        st.push(j);
      }
      else{
        st.push(i);
      }
    }
    int pos = st.pop();
    for(int i = 0; i <a.length; i++){
      if(i!=pos){
      if(a[i][pos] == 0 || a[pos][i]==1){
        
        return -1;
      }
    }
    } 

    return pos;
  }
   public static void main(String[] args) throws Exception{

    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();

    int a[][] = new int[n][n];

    for(int i = 0; i <n; i++){

      for(int j = 0; j <n; j++){

        a[i][j] = sc.nextInt();
      }
    }
    

    System.out.println(solve(a,n));
  }
}
