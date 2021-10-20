package sorting;

import java.util.Arrays;

public class CycleSort {

	public static void main(String[] args) {
		System.out.println(Arrays.toString(cyclic(new int[] {3,5,1,4,2,8})));
	}
	
	static int[] cyclic(int arr[]) {
		int i=0; 
		while(i<arr.length) 
		{
			int crtIndex = arr[i] - 1;
			if(arr[i] != arr[crtIndex]) {
				arr[crtIndex] = arr[i] + arr[crtIndex] - (arr[i] = arr[crtIndex]);
			} else {
				i++;
			}
		}
		return arr;
	}

}
