#include <bits/stdc++.h>
using namespace std;

bool binarySearch(vector<int>array, int value){
    int low = 0;
    int high = array.size()-1;
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

int main(){
    vector<int>arr = {-18, -12, -8, -5, 0 , 5, 10, 13, 16, 18};
    int target = 13;
    bool ans = binarySearch(arr, target);
    if(ans == true){
        cout << "Target number exists in the array" <<endl;
    }else{
        cout << "Target number does not exists in the array" <<endl;
    }


}