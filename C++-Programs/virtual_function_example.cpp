#include<iostream>

using namespace std;

class Figure
{
protected:
    float dim1, dim2;
public:
    Figure(float a, float b)
    {
        dim1= a;
        dim2= b;
    }
    virtual float Area()
    {
        return 0.0;
    }
};
    class Rectangle: public Figure
    {
    public:
        Rectangle(float length, float breadth): Figure(length, breadth)
        {
        }
        float Area()
        {
            return(dim1*dim2);
        }
    };
     class Triangle: public Figure
    {
    public:
        Triangle(float height, float base): Figure(height, base)
        {

        }
        float Area()
        {
            return ((dim1*dim2)/2);
        }
    };

int main()
{
    Figure *f;
    Rectangle rect(10.05, 7.0);
    Triangle tri(10.5, 5.6);
    float area_rect, area_tri;
    f=&rect;
    area_rect=f->Area();
    f=&tri;
    area_tri=f->Area();
    cout<<"area of rectangle"<<area_rect<<endl;
    cout<<"area of triangle"<<area_tri<<endl;
    return 0;
}

