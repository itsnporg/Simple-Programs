import java.util.Scanner;
import java.text.*;
public class Freezer {
public static void main(String[] args) {
    NumberFormat nf=NumberFormat.getInstance();
    Scanner sc=new Scanner(System.in);
    int t1;
    float Temp, t2;
    System.out.println("Enter Time since power failure..! ");
    System.out.println("Enter Hours: ");
    t1=sc.nextInt();
    System.out.println("Enter Minutes: ");
    t2=sc.nextFloat();
    sc.close();
    t2=t2/60;
    float hours=t1+t2;
    nf.setMaximumFractionDigits(2);
    System.out.println("Total time elapsed since power failure " +nf.format(hours)+"hrs");
    Temp=(4*(hours*hours))/(hours+2)-20;
    System.out.println("Current temperature of the freezer = " + Temp +" Celsius");
  }
}
