package com.saikat;

public class kthLargestElement {
    public static void main(String[] args) {
       int[] nums = { 3,2,3,1,2,4,5,5,6};
       int k = 4;
        System.out.println(sort(nums,k));
    }
    static int sort(int[] arr, int k){
        int i = 0;
        while (i < arr.length){
            int correctIndex = arr[i] -1;
            if (arr[i] != arr[correctIndex]){
                swap(arr,i,correctIndex);
            }else{
                i++;
            }
        }
        for (int j = 0; j < arr.length; j++) {
            return arr[arr.length-k];
        }
        return -1;
    }

    static void swap(int[] arr, int first, int second){
        int temp = arr[first];
        arr[first] = arr[second];
        arr[second] = temp;
    }
}
