#include <iostream>

using namespace std;
class Fahrenheit;
class Celsius{
private:
    float x;
public:
    Celsius(float a){
    x=a;
    }
    void display(){
    cout<<"Celsius:"<<x<<endl;
    }

    operator Fahrenheit();
};
class Fahrenheit{
private:
    float x;
public:
    Fahrenheit(float a){
    x=a;
    }
    void display(){
    cout<<"Fahrenheit:"<<x<<endl;
    }

    operator Celsius(){
    return Celsius((x-32)/1.8);
    };
};
Celsius::operator Fahrenheit(){
    return Fahrenheit((x*1.8)+32);
};

int main(){
    Celsius c(100);
    c.display();
    Fahrenheit f=(Fahrenheit)c;
    f.display();
    return 0;
}
