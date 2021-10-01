#include <iostream>
using namespace std;
template <class T>

void minim(T a[],int n){
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(a[i] > a[j]){
            T temp;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        }
    }

    for (int i = 0; i < n;i++)
        cout << a[i] << " ";
    cout << endl<<endl;
}

int main()
{
    int a[10];
    float b[10];

    cout << "For INT" << endl;
    int n,k;
    cout << "How many numbers ? ";
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }

    cout << "For Float" << endl;
    cout << "How many numbers ? ";
    cin >> k;
    for (int i=0; i<k; i++){
        cin >> b[i];
    }

    cout <<"\n\nSoritng in asscending order : \n\n";
    cout << "For INT array : "<<endl;
    minim(a, n);
    cout << "For Float array : "<< endl;
    minim(b, k);
    return 0;
}