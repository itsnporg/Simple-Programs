public class LargestSecondElementInArray {
	static int LargestElement(int arr[]){
	int largest = 0;
	for(int i=0;i<arr.length-1;i++) 
	{
		if(arr[i]>arr[largest]) 
		{
			largest = i;
		}
	}
	return largest;
	}
	static int SecondLargest(int arr[]) {
	int largest = LargestElement(arr);
	int res = -1;
	for(int i = 0;i<arr.length-1;i++) 
	{
		if(arr[i]!=arr[largest]) 
		{
			if(res==-1)
			res=1;
			else if(arr[i]>arr[res])
			res = i;
			}
		}
		return arr[res];
	}
	public static void main(String[] args) {
		int arr[] = {5,10,8,20};
		System.out.println(SecondLargest(arr));
	}
}
