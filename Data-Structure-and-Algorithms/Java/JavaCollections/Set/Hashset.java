import java.util.*;
public class Hashset{

  public static void main(String[] args){

    Set<Integer> set = new HashSet<>();
    // Set<Integer> set = LinkedHashSet<>() order will be maintained
    //  Set<Integer> set = new TreeSet<>();
    //  sorted ordder


    set.add(32);
    set.add(45);
    set.add(32);
    set.add(44);
    set.add(12);

    set.remove(12);

    System.out.println(set.contains(100));
    System.out.println(set);
    System.out.println(set.size());
    set.clear();
    System.out.println(set);
  }

}
