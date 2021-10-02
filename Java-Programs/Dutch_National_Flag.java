
public class Dutch_National_Flag {
	
	public static void DNF(String A[]) {
		int n=A.length;
		int low=0,high=n-1,mid=0;
		String temp;
		while(mid<=high) {
			switch(A[mid]) {
			case "RED":
				temp=A[low]; A[low]=A[mid]; A[mid]=temp;
				low++;mid++;
				break;
			case "BLUE":
				mid++;
				break;
			case "GREEN":
				temp=A[mid]; A[mid]=A[high]; A[high]=temp;
				high--;
				break;
			}
		}
	}
	public static void Display(String A[]) {
		for(int i=0;i<A.length;i++) {
			System.out.print(A[i]+" ");
		}
		System.out.println();
	}

	public static void main(String[] args) {
		String A[]= {"RED","BLUE","BLUE","RED","GREEN","GREEN","RED","RED","BLUE","GREEN"};
		Display(A);
		DNF(A);
		Display(A);
	}

}
