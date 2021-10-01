/* static is used when same data is to be used 2+ times
it can be used,accessed and changed using different....
static can be used as counter
*/
#include <iostream>
using namespace std;

class student
{
public:
    int roll;
    string name;
    static int AddmissionNo;
    student(string n) {
        AddmissionNo++;
        name = n;
        roll=AddmissionNo;
    }
    void display() { cout << "Name " << name << endl<< "Roll no : " << roll << endl; }
};

int student::AddmissionNo=0;

int main()
{
    student s1("Nisham");
    student s2("Ravi");
    student s3("Aayush");
    student s4("Aavash");
    student s5("Aseem");
    student s6("Alisha");
    student s7("Aabha");

s1.display();
s4.display();
s5.display();

cout << "Total admissions : " << student::AddmissionNo << endl;
}
