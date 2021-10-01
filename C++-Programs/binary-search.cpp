// Binary Search

// Includes
#include <bits/stdc++.h>

// Function prototypes
int search(int arr[], int l, int n, int x);

// Main function
int main() {
	int arr[] = {10, 20, 30, 40, 50};
	int x = 5;
	int n = sizeof(arr)/sizeof(arr[0]);
	int result = search(arr, 0, n-1, x);
	std::cout << result;
	return 0;
}

// Binary search function
// It needs sorted array
// It compares the middle element of the array with the element to be searched
// If its middle element it returns the index
// if its greater then left half is again taken recursively
// else right half is taken recursively
int search(int arr[], int l, int n, int x) {
	int index = -1;
	if(n >= l) {
		int mid = l + (n-1) / 2;
		if(arr[mid] == x) {
			index = mid+1;
			return index;
		}
		if(arr[mid] > x) {
			return search(arr, l, mid-1, x);
		}

		return search(arr, mid+1, n, x);
	}
	return index;
}