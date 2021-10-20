#include<iostream>
using namespace std;

class base{
    public:
    void display(){
        cout<<" THIS IS Base CLASS"<<endl;
    } 
};

class derived : public base{        //Inheriting base class 
     public:
  void display(){
        cout<<" THIS IS Derived CLASS"<<endl;
    } 

};

int main(){
 
 base obj1;         ////CREATING A BASE OBJECT
 obj1.display();

  derived obj2;     ////CREATING A DERIVED OBJECT
  obj2.display();      

    return 0;
}