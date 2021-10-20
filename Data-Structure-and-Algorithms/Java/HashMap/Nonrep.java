import java.io.*;
import java.util.*;
public class Nonrep{
  public static void main(String[] args) {
    int arr[] = {-1,-1,2,4,3};

     HashMap<Integer, Integer> hm = new HashMap<>();
        
        for(int val: arr){
            
            if(hm.containsKey(val)){
                int of = hm.get(val);
                int mf = of+1;
                hm.put(val,mf);
            }
            
            else{
                
                hm.put(val,1);
            }
        }

        for(int i: hm.keySet()){

          if(hm.get(i) == 1){
            System.out.println(i);
          }
        }


    }
  }

