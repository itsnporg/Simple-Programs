#include<iostream>

using namespace std;

class Distance
{
private:
    int meter, centi;
public:
    Distance()
    {
        meter= 0;
        centi= 0;
    }
    Distance (int m, int cm)
    {
        meter= m;
        centi=cm;
    }
    Distance operator + (Distance d)
    {
        Distance temp;
        temp.meter= meter + d.meter;
        temp.centi= centi + d.centi;
        if(temp.centi>100)
        {
            temp.meter++;
            temp.centi= temp.centi -100;
        }
        return temp;
    }
    void display()
    {
        cout<<meter<<"m"<<centi<<"cm"<<endl;
    }
};

int main()
{
    Distance d1(2,34), d2(4, 65), d3;
    d3= d1.operator+(d2);
    cout<<"d1="<<d1.display();
    d2.display();
    d3.display();
    return 0;
}
