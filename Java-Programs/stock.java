import java.util.*;
public class stock
{
    public static void main(String args[])
    {
        int arr[]={3,9,5,8,1,7,4,10},i,min=arr[0],profit=0;
        for(i=1;i<arr.length;i++)
        {
            if(min>arr[i])
                min=arr[i];      //minimum value till that day
            if(profit<(arr[i]-min))
                profit=arr[i]-min;
        }
        System.out.print(profit);
    }
}