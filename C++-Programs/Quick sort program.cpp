#include <bits/stdc++.h>
using namespace std; 
  
void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
  
int part (int arr[], int l, int h) 
{ 
    int p = arr[h]; 
    int i = (l - 1); 
    for (int j = l; j <= h - 1; j++) 
    { 
        if (arr[j] < p) 
        { 
            i++;
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[h]); 
    return (i + 1); 
} 
  
void quickSort(int arr[], int l, int h) 
{ 
    if (l < h) 
    { 
        int p = part(arr, l, h); 
        quickSort(arr, l, p - 1); 
        quickSort(arr, p + 1, h); 
    } 
} 
  
void print(int arr[], int len) 
{ 
    for (int i = 0; i < len; i++) 
        cout << arr[i] << " "; 
    cout << endl; 
} 
  
int main() 
{ 
    int len;
    cout << "Enter array length";
    cin >> len;
    int arr[len];
    cout << "Enter array elements";
    for(int i=0; i<len; i++)
    {
        cin >> arr[i];
    }
    quickSort(arr, 0, len - 1); 
    cout << "The sorted array is : \n"; 
    print(arr, len); 
    return 0; 
} 