/* To find volume of sphere ,cylinder(πr2h) and cube using function overloading*/
#include <iostream>
#include <math.h>

using namespace std;

const float pie = 3.14;
void volume(float a)
{
    float v = 4.0 / 3 * pie * pow(a, 3);
    cout << "Volume of sphere is :" << v << endl;
}

void volume(float b, float c)
{
    cout << "volume of cylinder is : " << (pie * b * b * c) << endl;
}

void volume(int d)
{
    cout << "Volume of cube is : " << pow(d, 3);
}

int main(void)
{
    float a, b, c;
    int d;
    cout << "enter radius of sphere: ";
    cin >> a;
    volume(a);

    cout << "enter radius and height of cylinder : ";
    cin >> b >> c;
    volume(b, c);

    cout << "enter length of cube in integer : ";
    cin >> d;
    volume(d);
}
