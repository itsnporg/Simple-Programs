//Write a program to display all prime numbers less than 100.
import java.util.Scanner;

public class x{
    public static void main(String[] args) {
       inputThenPrintSumAndAverage();
    }
    public static void inputThenPrintSumAndAverage(){
        int num,sum=0;
        double avg;
        int count = 0;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter any number:");
        while (true)
        {
            boolean isItInt = sc.hasNextInt();
            if(isItInt)
            {

                num = sc.nextInt();
                sum += num;
                count++;
            }else
            {
                break;
            }
        }
        sc.close();
        avg =(double) sum/count;

        System.out.println("Sum "+ sum+" Average "+avg);
    }

}

