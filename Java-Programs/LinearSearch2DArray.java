package ARRAYS;

import java.util.Arrays;

public class LinearSearch2DArray {
	public static void main(String[] args) {
		int[][] arr = {
				{12, 34, 9},
				{13, 26, 76, -13, 43, 48},
				{56, 72}
		};

		int[] ans = search(arr, 72);
		System.out.println(Arrays.toString(ans));
	}

	static int[] search(int[][] arr, int target) {
		if (arr.length == 0) {
			System.out.println("Array is empty");
		}

		if (arr == null) {
			System.out.println("Initialize the array");
		}

		for (int i = 0; i < arr.length; i++) {
			for (int j = 0; j < arr[i].length; j++) {
				if (arr[i][j] == target) {
					return new int[]{i, j};
				}
			}
		}
		return new int[]{-1, -1};
	}
}
