import java.util.Random;
import java.util.Scanner;

public class NumberGuess{
    public static void main(String[] args) {
        Random rand = new Random();
        int num = rand.nextInt(100);

        Scanner sc = new Scanner(System.in);

        for(int i=0;i<10;i++){
            System.out.println("Enter your guess Number: ");
            
            String chose = sc.nextLine();
            try{
                int choice = Integer.parseInt(chose);
                if(choice<num){
                    System.out.println("Smaller");
                } else if(choice<1 || choice>100){
                    System.out.println("Please enter number between 0 to 100");
                } else if(choice==num){
                    System.out.println("Your guess is correct");
                    break;
                } else{
                    System.out.println("Greater");
                }
            }
            catch(NumberFormatException e){
                System.out.println("Only enter numeric value");
            }
        }
        sc.close();
    }
}