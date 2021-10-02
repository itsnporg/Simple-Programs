import java.util.Scanner;
public class sumOfNaturalNumbers {
	public static void main(String[] args) {
		System.out.print("Enter a number: ");
		Scanner input=new Scanner(System.in);
        int number=input.nextInt();
		int sum = 0; 
		for(int i=1; i<=number;++i) {
			sum+=i;
    }
	System.out.println("sum = " + sum);
	}
}
