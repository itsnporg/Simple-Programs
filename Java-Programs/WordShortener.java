import java.util.Scanner;

/**
 * WordShortener program
 *
 * If the word length is more than 10, it will be convert to abbreviation
 * version. If the word length is 10 or less, it will be kept as it is
 *
 * E.g: inter -> inter, international -> i11n
 */
public class WordShortener {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String q = scan.next();
        int l = q.length();
        System.out.println((l > 10) ? q.charAt(0) + "" + (l - 2) + "" + q.charAt(l - 1) : q);
        scan.close();
    }
}
