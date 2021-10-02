import java.util.*;

public class FindFrequency
{
    
    public static void findFrequency(int[] array){
        
        HashMap<Integer,Integer> hashMap = new HashMap<>(); // Declare the HashMap.
        
        // Compute the frequency of an array elements
        for(int index=0; index<array.length; index++){
            if(hashMap.containsKey(array[index])){
                hashMap.put(array[index],hashMap.get(array[index])+1);
            }else{
                hashMap.put(array[index],1);
            }
        }
        
        // Display the result.
        for (Map.Entry<Integer, Integer> e : hashMap.entrySet())
            System.out.println(e.getKey()+ ": " + e.getValue());
        
    }
    
	public static void main(String[] args) {
	    
		Scanner scan = new Scanner(System.in);
		int sizeOfArray = 0; // declare the sizeOfArray variable.
		
		System.out.print("Enter the size of an array: "); // Message for user.
		sizeOfArray = scan.nextInt(); // Take input from the user.
		
		int[] array = new int[sizeOfArray]; // Declare the array of size sizeOfArray.
		
		System.out.println("Enter the elements in an array :"); // Message for user.
		for(int index=0; index<sizeOfArray; index++)
		    array[index] = scan.nextInt(); // Take input from the user in an array.
		
		findFrequency(array); // Call the findFrequency method.
		
	}
}
