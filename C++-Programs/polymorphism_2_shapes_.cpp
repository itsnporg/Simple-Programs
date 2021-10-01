#include <iostream>
using namespace std;

class Shape
{
    public:
        virtual void area()=0;
        virtual void perimeter()=0;
};

class circle : public Shape
{
    float radius;
public:
    circle(float r=1) { radius = r; }
    void area(){
        cout << "Area of Circle is : " << 3.1425 * radius * radius<<endl;
    }
    void perimeter(){
        cout << "Perimeter of Circle is : " << 2 * 3.1425 * radius << endl;
    }
};

class rectangle : public Shape
{
    int length, breadth;
public:
    rectangle(int l=1, int b=1) { length = l;breadth = b;}
    void area(){
        cout << "Area of Rectangle is : " << length * breadth<<endl;
    }
    void perimeter(){
        cout << "Perimeter of Rectangle is : " << (length + breadth) * 2 << endl;
        }
};

int main(){
    Shape *ptr = new circle(10);
    ptr->area();
    ptr->perimeter();

    ptr = new rectangle(5, 10);
    ptr->area();
    ptr -> perimeter(); 
}