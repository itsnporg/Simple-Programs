import java.io.*;
import java.util.Scanner;

class GCDFinder {
    public static void main(String[] args) {

        int num1,num2,gcd = 1;
        Scanner s = new Scanner(System.in);

        System.out.print("Enter Number1: ");
        num1 = s.nextInt();

        System.out.print("Enter Number2: ");
        num2 = s.nextInt();

        for (int i = 1; i <= num1 && i <= num2; ++i) {
            if (num1 % i == 0 && num2 % i == 0)
                gcd = i;
        }

        System.out.println("GCD of " + num1 +" & " + num2 + " : " + gcd);
    }
}