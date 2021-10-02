package isufficientbalanceexception;
import java.util.Scanner;
 class IsufficientBalanceException {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        BankAccount ba=new BankAccount();
        Scanner sobj=new Scanner(System.in);
        System.out.println("Enter amount to deposit:");
        double da=sobj.nextDouble();
        System.out.println("Enter amount to withdraw:");
        double wa=sobj.nextDouble();
        ba.deposit(da);
        try{
          ba.Withdraw(wa);
        }
        catch(MyException e)
        {
           System.out.println("Excepption caught!!"+e);
        }
    }
    
}
