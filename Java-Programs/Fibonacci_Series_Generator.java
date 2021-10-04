// This generate the fibonacci series up to the user input number

import java.util.Scanner;

public class Fibonacci_Series_Generator {

	public static void main(String[] args) {
		
		int f1 = 0, f2 = 1;
		
		// take user input
				Scanner reader = new Scanner(System.in);
				System.out.print("Enter an integer: ");
				
				int n = reader.nextInt();

		
		System.out.print("Upto " + n + ": ");
		
		//Calculate and display fibonacci series upto n numbers
		while (f1<= n)
		{
		System.out.print(f1 + "  ");
		int sum = f1 + f2;
		f1 = f2;
		f2 = sum;
		}

	}

}
