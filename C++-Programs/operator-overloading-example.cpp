#include <iostream>
using namespace std;
class IncreDecre{
    int a,b;
    public:
    void getdata()
        {
            cout << "Enter two numbers:" << endl;
            cin >> a >> b;
        }
    
    void operator --() // Operator Overloading
        {
            a--;
            b--;
        }

    void operator ++() //Operator Overloading
        {
            a++;
            b++;
        }
    void display()
        {
            cout << "A=" <<a << endl;
            cout << "B= " << b << endl;
        }
};

int main()
    {
        system("clear");
        IncreDecre id;//Making Object of a Function
        id.getdata();//Calling Getdata member function of the class IncreDecre
        --id; //Operator Overloading
        cout << "After Decrementing:" << endl;
        id.display(); //Calling display member function of class IncreDecre
        ++id;
        ++id;
        cout << "After Incrementing:" << endl;
        id.display(); //Calling display member function of class IncreDecre
        return 0;
    }
