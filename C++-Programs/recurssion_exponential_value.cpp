#include <iostream>
#include <iomanip>

using namespace std;

double e(int x,int n)
{
    static double p = 1, f = 1;
    double r;

    if (n==0)
        return 1;
    r = e(x, n - 1); 
    p *= x; // numerator term x^n
    f *= n; // denominator factorial of number
    return r + p / f;  //adding back terms
}

int main(){
    cout << "Enter e^x _(x value and number of terms u want to check : ";
    int x, n;
    cin >> x >> n;
    cout <<setprecision(n)<< "e^" << x << " = " << e(x, n)<<endl;
}