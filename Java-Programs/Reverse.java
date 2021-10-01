package ARRAYS;

import java.util.Arrays;


//In this algo, Since we are using two pointers start and end,it is called two pointer method.......

public class Reverse {
	public static void main(String[] args)
	{
		int[] arr = {2, 6, 4, 9, 1, 3, 5, 7, 13, 24, 29, 30};
		System.out.println(Arrays.toString(arr));
		reverse(arr);
		System.out.println(Arrays.toString(arr));
	}

	static void reverse(int[] arr)
	{
		int start=0;
		int end=arr.length-1;
		while(start<end)
		{
			swap(arr,start,end);
			start++;
			end--;
		}
	}

	static void swap(int[] arr,int index1,int index2)
	{
		int temp=arr[index1];
		arr[index1]=arr[index2];
		arr[index2]=temp;
	}
}
