#include <iostream>

using namespace std;

class Num2;

class Num1
{
    int n1;

public:
    friend class Num2;
    void setdata(int a)
    {
        n1 = a;
    }

    void printdata()
    {
        cout << "Num1: " << n1 << endl;
    }
};

class Num2
{
    int n2;

public:
    void setdata(int a)
    {
        n2 = a;
    }

    void numswap(Num1 &o1, Num2 &o2)
    {
        int temp = o1.n1;
        o1.n1 = o2.n2;
        o2.n2 = temp;
    }

    void printdata()
    {
        cout << "Num2: " << n2 << endl;
    }
};

int main()
{
    Num1 num;
    Num2 number;

    num.setdata(3);
    number.setdata(4);

    number.numswap(num, number);

    num.printdata();
    number.printdata();
    return 0;
}