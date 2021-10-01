#include <iostream>

using namespace std;
template <class T>

T maxim(T x,T y){
    return x > y ? x : y;
}

int main()
{
    cout << "INT function max is " << maxim(5, 10) << endl;
    cout << "Float function max is " << maxim(5.12f, 10.343f) << endl;
    return 0;
} 