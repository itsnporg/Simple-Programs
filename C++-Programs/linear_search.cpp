#include <iostream>
using namespace std;

int search (int (&a)[10], int key,int *p)
{
    int count = 0;
    for (int x : a)
    {
        *p += x;
        if (x == key)
            return count;

        count++;
    }
    return 0;
}
int main() {
    int A[10] = {1, 2, 3, 42, 45, 67, 77, 98, 99, 101};
    int key, p, k = 0;
    cout << "Enter searching key : ";
    cin >> key;
    p = search(A, key,&k);

    cout << "Average till the key is : " << (float)k / 10 << endl;

    if(p==0)
        cout << "Not found ,sorry." << endl;
    else
        cout<<"Found at " << p << endl;
    return 0;
    }

//NEXT METHOD


// #include <iostream>
// using namespace std;

// int search (int A[],int key,int count){
//     for(int i = 0; i < count; i++){
//         if(A[i] == key)
//             return i;
//     }
//     return -1;
// }

// int main() {
//     int A[10] = {1, 2, 3, 42, 45, 67, 77, 98, 99, 101};
//     int key,p;
//     cout << "Enter searching key : ";
//     cin >> key;

//     p= search(A, key, 10);

//     if(p==-1)
//         cout << "Not found ,sorry." << endl;
//     else
//         cout<<"Found at " << p << endl;
//     return 0;
//     }