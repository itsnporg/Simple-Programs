import java.util.Scanner;

/**
 * This program will convert the temperature in Fahrenheit to Celsius
 */
public class FahrenheitToCelsiusConverter {
    public static void main(String arg[]) {
        double a;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter  Fahrenheit temperature");
        a = sc.nextDouble();
        System.out.println("Celsius temperature is = " + celsius(a));
        sc.close();
    }

    static double celsius(double f) {
        return (f - 32) * 5 / 9;
    }
}
