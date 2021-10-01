#include <iostream>
using namespace std;

class rectangle
{
    private:
    int length;
    int breadth;

    public:
    rectangle (int l=1,int b=1){ //constructor with default values
        setLength(l);
        setBreadth(b);
    }
    rectangle (rectangle &r){ //copy constructor
        length=r.length;
        breadth=r.breadth;
    }
    void setLength(int l){
        if(l>0)
            length = l;
        else
            length = -l;
    }
    void setBreadth(int b){
        if(b>0)
            breadth = b;
        else
            breadth = -b;
    }

    int area(){
        return length * breadth;
    }

    int perimeter(){
        return (length+breadth) * 2;
    }
};

int main()
{
    rectangle *p = new rectangle; //heap memory
    //pointer to objects
    p->setLength(5);  
    p->setBreadth(10);

    rectangle r1(3, 5);
    rectangle r2(r1); //passing to copy constructor
    cout << "area is : " << r2.area() << endl;

    cout<< "Area of reactangle is : " << p->area() << endl;
    cout << "Perimeter of reactangle is : " << p->perimeter() << endl;
}
