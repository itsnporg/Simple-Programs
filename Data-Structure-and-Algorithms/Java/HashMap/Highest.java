import java.util.*;
import java.io.*;

public class Highest{

  public static void main(String[] args) {
    
    Scanner sc = new Scanner(System.in);
    String s = sc.nextLine();

    HashMap<Character, Integer> hm = new HashMap<>();
    
    for(int i = 0; i <s.length(); i++){

      char c = s.charAt(i);

      if(hm.containsKey(c)){
        
        int of = hm.get(c);

        int nf = of+1;
        hm.put(c,nf);
      }
      else{
        hm.put(c,1);
      }

    }
    // set the first as 

    char mfc = s.charAt(0);


    for(Character key: hm.keySet()){
      if(hm.get(key) > hm.get(mfc)){
        mfc = key;
      }
    }
    System.out.println(mfc);
  }
}
