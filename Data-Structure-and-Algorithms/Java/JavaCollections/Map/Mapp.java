import java.util.HashMap;
import java.util.Map;
import java.util.TreeMap;

public class Mapp{

  public static void main(String[] args){

    Map<String, Integer> number = new HashMap<>();
    
    // key and index 
    number.put("One",1);
    number.put("Two",2);
    number.put("Three",3);

    //number.remove("Three");

    System.out.println(number.containsValue(3));

    System.out.println(number.isEmpty());

    if(!number.containsKey("Three")){
      number.put("Three",3);
    }
    if(!number.containsKey("Four")){
      number.put("Four",4);
    }


    for(Map.Entry<String, Integer> e: number.entrySet()){
      //System.out.println(e);
      System.out.println(e.getValue());
      System.out.println(e.getKey());

    }

    for(String key: number.keySet()){
      System.out.println(key);
    }

    for(Integer value: number.values()){
      System.out.println(value);
    }

    
    System.out.println(number);

    
  }
}

