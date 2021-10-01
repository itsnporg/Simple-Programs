
import java.util.*;
  
  public class Prime{
  
  public static void main(String[] args) {
      Scanner scn = new Scanner(System.in);
  
       // write ur code here
       
      
       
       
       int t=scn.nextInt();

       for(int j=0; j<t; j++){

       
       int n = scn.nextInt();

       int count=0;
       
       for(int i=1; i<=n; i++){

           if(n%i==0){
               count++;
           }
       }
        if(count==2){
        System.out.println("prime");
        }else{
        System.out.println("not prime");
    }

    }
   }
}
