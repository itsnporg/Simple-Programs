import java.util.*;
import java.io.*;
import java.lang.*;
public class Code{

  public static void main(String[] args){

    Scanner sc = new Scanner(System.in);
    int t = sc.nextInt();

    while(t-- >0){
    int x = sc.nextInt();
    int a = sc.nextInt();
    int b = sc.nextInt();

    int res = a+(100-x)*b;
    
    System.out.println(res*(10));
  }
  
}
}
