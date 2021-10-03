//Question:-
//Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,4,4,5,6,7] might become:
//[4,5,6,7,0,1,4] if it was rotated 4 times.
//[0,1,4,4,5,6,7] if it was rotated 7 times.
//Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].
//Given the sorted rotated array nums that may contain duplicates, return the minimum element of this array.
//You must decrease the overall operation steps as much as possible.
//Answer:-
class Solution {
    public int findMin(int[] nums) {
        if(nums.length ==2){
            if(nums[0]>nums[1])
                return nums[1];
        return nums[0];
        }
        int p = pivot(nums);
        if(p!=-1  && p != nums.length)
            return nums[p+1];
         else
          return nums[0];
    }

    public int pivot(int[] arr){
        int start =0;
        int end =arr.length-1;
        while(start<end){
            int m = start + (end -start)/2;
            if( m < end && arr[m]>arr[m+1])
                return m;
            if( m >start && arr[m]<arr[m-1] )
                return m-1;
            if(arr[m]==arr[start] && arr[m]==arr[end]){
                if(arr[start] > arr[start+1]  )
                    return start;
                start++;
                if(arr[end]<arr[end]-1)
                    return end -1;
                end--;

            }
           if(arr[m]>arr[start] || (arr[m]==arr[start] &&arr[m]>arr[end]))
               start =m+1;
            else
                end =m-1;
        }
        return -1;
    }
}
