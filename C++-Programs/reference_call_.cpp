#include <iostream>
using namespace std;

template <class T>

void swaps (T &a,T &b){
    T temp;
    temp = a;
    a = b;
    b = temp;
}

int main()
{
    int x = 10, y = 30;
    float c = 34.2, d = 25.34;
    cout << "Before swap int: " << x << "," << y << endl;
    cout << "Before swap float: " << c << "," << d << endl<<endl;
    swaps(x, y);
    swaps(c, d);
    cout << "After swap int: "<< x <<","<< y<<endl;
    cout << "After swap float: "<< c <<","<< d <<endl;
}