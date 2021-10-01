#include <iostream>
using namespace std;

int main(){
    cout << "Enter 2 numbers : ";
    int n1, n2;
    cin >> n2 >> n1;
    int sum = [](int a,int b)->int{ return a+b; }(n1,n2);

    cout << "Sum is : "<< sum << endl;
}