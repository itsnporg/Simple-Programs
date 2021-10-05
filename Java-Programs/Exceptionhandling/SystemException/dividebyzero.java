//Program to demonstrate system Exception:
package systemexceptions;
public class dividebyzero {

 
    public static void main(String[] args) {
        // TODO code application logic here
        int a,b,c;
        a=0;
        b=5;
        try{
           c=b/a;
           System.out.println("the division is:"+c);
        }
        catch(ArithmeticException e){
           System.out.println("Exception caught!!"+e);
        }
        finally{
         System.out.println("Inside the final block");
        }
    }
    
}
