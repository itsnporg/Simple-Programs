import java.util.Arrays;

public class MergeWihoutSpace {
	
	public static void merge(long arr1[] , long arr2[] , int n ,int m) {
		
		int i = 0 , j=0 ,k=n-1;
		
	while(i<=k && j<m) {                                                 
			
			if(arr1[i]<arr2[j])
				i++;
			else {
				long temp = arr2[j];
				arr2[j]=arr1[k];
				arr1[k]=temp;
				j++;
				k--;
			}
		}
		Arrays.sort(arr1);
		Arrays.sort(arr2);
		
		
	}
	
		


	public static void main(String[] args) {

        long a[] = {1, 3 ,5, 7} ;
        long b[] = {0 ,2, 6, 8 ,9} ;
        
        int l1 = a.length;
        int l2 = b.length;
        
        merge(a,b,l1,l2);
        
        StringBuffer str = new StringBuffer();
	    for(int i=0; i<l1; i++){
	        str.append(a[i]+" ");
	    }
	    for(int i=0; i<l2; i++){
	        str.append(b[i]+" ");
	    }
	    System.out.println("The Merged Array is :");
	    System.out.println(str);
	}
       
        
  }


