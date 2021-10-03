import java.util.HashMap;
import java.util.Map;
import java.util.TreeMap;

public class Map{

  public static void main(String[] args){

    Map<String, Integer> number = new HashMap<>();
    
    // key and index 
    number.put("One",1);
    number.put("Two",2);
    number.put("Three",3);

    System.out.println(number);
  }
}
