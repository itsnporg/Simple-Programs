public class Main {
    public static void main(String[] args) {
        int[] arr = {-18, -12, -8, -5, 0 , 5, 10, 13, 16, 18};
        int target = 13;
        boolean ans = binarySearch(arr, target);
        if(ans == true){
            System.out.println("Target number exists in the array");
        }else{
            System.out.println("Target number does not exists in the array");
        }
    }
    static boolean binarySearch(int[] array, int value){
        int low = 0;
        int high = array.length-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(array[mid] == value){
                return true;
            }else if(value > array[mid]){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return false;
    }
}