import java.util.*;
import java.io.*;
public class GetCommon{

  public static void main(String[] args) {
    
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();

    int a[] = new int[n];
    int b[] = new int[n];
    for(int i = 0; i <n; i++){

      b[i] = sc.nextInt();
    }

    for(int i = 0; i <n; i++){

      a[i] = sc.nextInt();
    }

    HashMap<Integer, Integer> hm = new HashMap<>();


    for(int val: a){

      if(hm.containsKey(val)){

        int of = hm.get(val);
        int nef = of+1;
        hm.put(val, nef);
      }

      else{

        hm.put(val, 1);
      }
    }

    for(int val: b){
      
      if(hm.containsKey(val) && hm.get(val) > 0){
        System.out.println(val);
        int of = hm.get(val);
        int nf = of-1;
        hm.put(val, nf);
        
      }
    }
  }
}

























