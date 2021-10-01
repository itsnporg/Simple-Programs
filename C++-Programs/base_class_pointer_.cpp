//base class pointer pointing to derived class
#include <iostream>
using namespace std;

class ParentClass{
    public:
        void func1() { cout << "From parent :) " << endl; }
};

class ChildClass: public ParentClass{
    public:
        void func2() { cout << "From child :) " << endl; }
};

int main() {
    ChildClass derived;
    ParentClass *pointer = &derived;
    pointer -> func1();
    //pointer -> func2();  [not available because it's in parentclass which can't be accessed from base pointer] 
}