import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter the number: ");
        int num = in.nextInt();
        int factor = 1;
        while (factor<=num){
            if (num%factor==0){
                System.out.println(factor);
            }factor = factor + 1;
        }
    }
}