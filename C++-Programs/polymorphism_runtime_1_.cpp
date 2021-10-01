/* Polymorphism: 
1. Same nam with different actions
2. Need function overrides
3. Virtual functions*
4. Derived classes mustttt override existing function in base class
5. Base class pointer pointing to derived class objects
*/

#include <iostream>
using namespace std;

class Human {
    public:
        virtual void print()=0;  //pure virtual function__must be override
    //if != 0 then derived classes becomes abstract & no object can be created
};

class Male: public Human{
    public:
        void print(){ cout << "I am Male"<<endl; }
};

class Female: public Human{
    public:
        void print() { cout << "I am Female" << endl; }
};

int main(){
    Human *ptr = new Male();
    ptr->print();
    ptr = new Female();
    ptr->print();
}