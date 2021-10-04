import java.util.Scanner;

public class CelsiusToFahrenheit{
    public static void main(String args[]){
        Scanner input = new Scanner(System.in);
        double celsius;
        double fahrenheit;

        System.out.print("Enter Temperature in Celsius : ");
        celsius = input.nextDouble();

        // Fahrenheit formula
        fahrenheit = (celsius * 1.8) + 32;

        System.out.println("Temperature in Fahrenheit : " + fahrenheit);
    }
}