import java.util.ArrayList;
import java.util.List;
public class List2{

  public static void main(String[] args){

    List<Integer> list1 = new ArrayList();
    list1.add(1);
    list1.add(2);
    list1.add(3);

    System.out.print(list1);

    List<Integer> list2 = new ArrayList();

    list2.add(45);
    list2.add(56);

    System.out.println(list2);

    list1.add(1,13);
    System.out.println(list1);

    list1.addAll(list2);
    System.out.println(list1);

    // get the element 
    System.out.println(list1.get(1));
    // remove 
    list1.remove(1);
    System.out.println(list1);

    list1.remove(Integer.valueOf(45)); // 45 is removed

    System.out.println(list1);

    // delete all the list elements 
    //list2.clear();

    // set the value;
    list1.set(1,122);

    System.out.println(list1);
    System.out.println(list1.contains(122));

    // Iterating 

    // method 1

    for(int i=0; i<list1.size();i++){
      System.out.println(list1.get(i));
    }

    // method 2

    for(Integer elem: list1){
      System.out.print(elem+" ");
    }

    // using Iterator 

    Iterator<Integer> it  = new Integer();
    while(it.hasNext()){
      System.out.print(it.next()+" ");
    }



  }
}
