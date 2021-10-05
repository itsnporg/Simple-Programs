import java.util.Scanner;
import java.util.Arrays;

public class ReverseArrays {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int[] arr;

        System.out.print("Enter the size of array : ");
        arr = new int[input.nextInt()];

        System.out.println("\nEnter " + arr.length + " elements :  ");
        for (int i = 0; i < arr.length; i++) {
            arr[i] = input.nextInt();
        }
        System.out.println("Original array : " + Arrays.toString(arr));
        reverse(arr);
        System.out.println("Reversed array : " + Arrays.toString(arr));
    }

    static void reverse(int[] a) {
        int end = a.length-1;
        for (int i = 0; i < a.length; i++) {
            if( i < end){
                swap(a,i,end);
                end--;
            }else{
                return;
            }
        }
    }

    static void swap(int[] arr, int index1, int index2) {
        int temp = arr[index1];
        arr[index1] = arr[index2];
        arr[index2] = temp;
    }
}