import java.util.Scanner;
public class reverseNumber {
	public static void main(String[] args) {
		System.out.print("Enter a number: ");
		Scanner input=new Scanner(System.in);
    int number=input.nextInt();
		int r = 0; 
		while(number !=0){
			int digit=number%10;
			r=r*10+digit;
			number /=10;
    }
	System.out.println("reversed number is " + r);
	}
}
