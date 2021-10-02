#include <iostream>

using namespace std;
class base{
protected:
    int a=9;
};
class Derived1:public virtual base{
};
class Derived2:public virtual base{
};
class Derived3:public Derived1,public Derived2{
    int b=a;
public:
    void display(){
    cout<<b;
    }
};
int main()
{
    Derived3 d;
    d.display();
    return 0;
}
