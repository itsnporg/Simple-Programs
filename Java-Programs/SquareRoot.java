package Assignments;

import java.util.Scanner;

public class SquareRoot {
	
	static int sqrt(int n) {
		int num =n;
		if (num==0 || num ==1) {
			return num;
		}
		int i,result=0;
		
		for(i=0; result<=num; i++  ) {
			result = i*i;
		}
		return i-2;
		
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		System.out.println(sqrt(n));

	}

}
