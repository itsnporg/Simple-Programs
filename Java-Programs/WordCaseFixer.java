import java.util.Scanner;

/**
 * Word case fixer program
 *
 * Fix all the case in the given word.
 *
 * If the word contains a majority of uppercase characters, it will be fixed
 * into all uppercase word.
 *
 * E.g: TeS -> TES
 *
 * If the word contains a majority of lowercase characters, it will be fixed
 * into all lowercase word.
 *
 * E.g: Tes -> tes
 */
public class WordCaseFixer {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.next();
        if (str.chars().filter(c -> c < 97).count() * 2 > str.length()) {
            System.out.print(str.toUpperCase());
        } else {
            System.out.println(str.toLowerCase());
        }
        sc.close();
    }
}
