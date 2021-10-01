#include <iostream>
using namespace std;
int main(){
    int A[10] = {1, 2, 3, 42, 45, 67, 77, 98, 99, 101};
    int i, mid, l=0, h=9,key;
    cout<< "Enter Searching key : ";
    cin >> key;
    while (l<=h){
        mid = (l+h)/2;
        if(key==A[mid]){
            cout << "Key found at " << mid;
            exit(0);
        }
        else if (A[mid]>key){
            h = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << "key is not found";
    return 0;
}