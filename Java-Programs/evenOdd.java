import java.util.*;
public class evenOdd {

	public static void main(String[] args) {
		System.out.println("Enter a number: ");
		Scanner input=new Scanner(System.in);
        int num=input.nextInt();
        if(num%2==0) {
        	System.out.print("Even");
        }
        else {
        	System.out.print("Odd");
        }   
	}
}
