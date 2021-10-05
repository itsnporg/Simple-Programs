
public class SelectionSort {

    int find_min(int arr[], int start, int end) {
        int min_idx = start;
        int minimum = arr[start];
        for (int i = start; i < end; i++) {
            if (arr[i] < minimum) {
                min_idx = i;
                minimum = arr[i];
            }
        }
        return min_idx;
    }

    void selection_sort(int arr[], int arr_len) {
        // Selection Sort on an Array
        // Pass by reference 
        int start = 0;
        int min_idx;
        while (start < arr_len) {
            min_idx = find_min(arr, start, arr_len);
            // Swap arr[start] and arr[min_idx]
            int temp = arr[start];
            arr[start] = arr[min_idx];
            arr[min_idx] = temp;
            start++;
        }
    }

    public static void main(String[] args) {
        int arr[] = {12, 7, 6, 16, 4};
        SelectionSort sel_sort = new SelectionSort();
        sel_sort.selection_sort(arr, 5);
        System.out.println("Array after sorting:");
        for (int i = 0; i < 5; i++) {
            System.out.printf(" ", arr[i]);
        }
        System.out.println();
    }
    
}
