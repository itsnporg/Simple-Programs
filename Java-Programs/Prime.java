import java.util.*;

public class Prime {

    public static void main(String[] args) {

        Scanner scn = new Scanner(System.in);
        int t = scn.nextInt();
        for (int j = 0; j < t; j++) {
            int n = scn.nextInt();
            if (n <= 0) {
                System.out.println("number must be greater than 0!");
                continue;
            }
            if (checkPrimeOrNot(n))
                System.out.println("Number is prime");
            else
                System.out.println("Number is not prime");
        }
        scn.close();
    }

    /*
     * This is the optimised code for checking if number is prime or not.
     * TC-O(sqrt(n)); It is three times faster than O(sqrt(n))
     */
    static boolean checkPrimeOrNot(int num) {
        if (num == 1)
            return false;
        if (num == 2 || num == 3)
            return true;
        if (num % 2 == 0 || num % 3 == 0)
            return false;
        for (int i = 5; i * i <= num; i++) {
            if (num % i == 0 || num % (i + 2) == 0)
                return false;
        }
        return true;
    }
}
