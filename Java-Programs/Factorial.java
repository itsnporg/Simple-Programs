import java.util.Scanner;
public class Factorial {
	public static void main(String[] args) {
		System.out.print("Enter a number: ");
		Scanner input=new Scanner(System.in);
    		int num=input.nextInt();
		long ans=factorial(n);
		System.out.printf("Factorial of %d = %d", num, ans);
	}
	
	public static long factorial (int n){
		return (n==1||n==0)? 1: factorial(n-1)*n;
	}
}
