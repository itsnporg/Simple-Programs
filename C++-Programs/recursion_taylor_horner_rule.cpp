#include <iostream>
using namespace std;

double e(int x,int n)
{
    static double s=1;
    if (n==0){
        return s;
    }
    s = (1 + x / n *s);
    return e(x, n - 1);
}

int main()
{
    cout << "Enter e^x for how many term separated with spaces :";
    int x, n;
    cin >> x, n;
    cout<< "e^" << x << " = " << e(x, n)<<endl;
}
