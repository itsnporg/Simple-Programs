import java.io.*;
import java.util.*;
public class Fr{

  public static void main(String[] args) {
   HashMap<Integer, Integer> hm = new HashMap<>();
   int a[] = {2,3,2,3,5};
   int n = 5;
   int p = 5;

   for(int i = 1; i <=n; i++){
     hm.put(i,0);
   }
   for(int val:a){

     if(hm.containsKey(val)){

       int of = hm.get(val);
       int nf = of+1;
       hm.put(val,nf);
     }
     else{
       
       hm.put(val,1);
     }
   }


   System.out.println(hm.get(1));
   System.out.println(hm);
   }
  }
