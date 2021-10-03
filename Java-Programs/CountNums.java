import java.util.Scanner;

public class CountNums {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter a number:");
        int n = in.nextInt();                //this will take input from user

        System.out.print("Enter number to count:");
        int a = in.nextInt();                 //this will take number that we need to find

        int count = 0;

        while(n>0){
            int rem = n % 10;                  //this will give the remainder
            if (rem == a){
                count++;                        //this will increment if the remainder is equal to the required number
            }
            n=n/10;                 //this will divide the input with 10
        }
        System.out.println(count);
    }
}
