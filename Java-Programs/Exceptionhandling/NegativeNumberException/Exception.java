package exceptionexample3;
//negative number Exception
import java.util.Scanner;
public class Exception {

  
    public static void main(String[] args) {
        CheckNum obj=new CheckNum();
        Scanner scan=new Scanner(System.in);
        System.out.println("Enter any positive number:");
        int num=scan.nextInt();
        try{
            obj.checknumber(num);
        }
        catch(NegativeNumberException e){
          System.out.println("Exception caught!!"+e);
        }
    }
    
}
