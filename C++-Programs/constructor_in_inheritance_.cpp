#include <iostream>
using namespace std;

class Base {
public:
    Base(){cout << "Non para Base " << endl;}
    Base(int x) { cout << "Param Of Base " << x<<endl; }
};

class Derived : public Base
{
    public:
    Derived() { cout << "Non para Derived " << endl; }
    Derived(int y) { cout << "Param of Derived " << y<<endl; }
    Derived(int x, int y):Base(x)
    {
        cout << "Para of Derived " << y << endl;
    }
};

int main()
{
    Derived d(10,5);
}