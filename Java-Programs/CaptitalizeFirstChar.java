import java.util.Scanner;

/**
 * This program will capitalize the first character of the given word.
 */
public class CaptitalizeFirstChar {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String t = sc.next();
        System.out.print((t.charAt(0) + "").toUpperCase() + t.substring(1));
        sc.close();
    }
}
