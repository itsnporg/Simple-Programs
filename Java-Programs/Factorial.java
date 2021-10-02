import java.util.Scanner;
public class Factorial {
	public static void main(String[] args) {
		System.out.print("Enter a number: ");
		Scanner input=new Scanner(System.in);
    int num=input.nextInt();
		long factorial=1;
		for (int i =1; i<=num; ++i) 
			factorial*=i;
		
		System.out.printf("Factorial of %d = %d", num, factorial);
	}
}
