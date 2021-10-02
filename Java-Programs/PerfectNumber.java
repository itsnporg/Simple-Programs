import java.util.Scanner;

public class PerfectNumber {

	public static void main(String args[]) {
		int sum = 0;
		Scanner sc = new Scanner(System.in);
		System.out.print("Pick a number:  ");
		long number = sc.nextInt(), i;
		System.out.print("The divisors of " + number + " are: 1 , ");
		// Calculates the divisors of the given number
		for (i = 2; i <= number / 2; i++) {
			if (number % i == 0) {
				System.out.print(i + " , ");
			}
		}
		System.out.println(number);
		// Checks if it is a perfect number
		for(int j = 1; j < number; j++)
		{
			if(number % j == 0)
			{
				sum = sum + j;
			}
		}
		if(sum == number) // If sum is the same as number, it is a perfect number
		{
			System.out.println(number + " is a perfect number!");
		}
		else // Otherwise it is not a perfect number
		{
			System.out.println(number + " is not a perfect number!");
		}   
		sc.close();
	}

	
}
