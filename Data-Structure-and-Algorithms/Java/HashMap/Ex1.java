import java.util.*;
import java.io.*;

public class Ex1{

  public static void main(String[] args) {

    HashMap<String, Integer> hm = new HashMap<>();
    hm.put("Nepal",13);
    hm.put("Np",45);
    hm.put("Football",432);

    hm.put("apple",43);

    hm.put("Nepal",56);
    System.out.println(hm);
    System.out.println(hm.containsKey("India"));
    System.out.println(hm.containsKey("Nepal"));
    

    // keySet will make the set of the keys present in the hashmap 
    Set<String> k = hm.keySet();

    System.out.println(k);

    // iterating throught the KeySet

    for(String key: hm.keySet()){
      Integer val = hm.get(key);

      System.out.println(key+" "+val);
    }
  }
}
