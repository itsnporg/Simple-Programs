#include <iostream>
//containership is to create an object of one class into another and that object will be a member of the class
using namespace std;
class Person{
private:
    char name[10];
    int age;
    char dob[10];
    char phn_no[10];
    char address[20];
public:
    void getData(){
    cout<<"Enter name:";
    cin>>name;
    cout<<"Enter age:";
    cin>>age;
    cout<<"Enter dob(dd/mm/yyyy):";
    cin>>dob;
    cout<<"Enter phone number:";
    cin>>phn_no;
    cout<<"Enter address:";
    cin>>address;
    }
    void showData(){
    cout<<"Name:"<<name<<endl;
    cout<<"Age:"<<age<<endl;
    cout<<"Dob:"<<dob<<endl;
    cout<<"Phone NO.:"<<phn_no<<endl;
    cout<<"Address:"<<address<<endl;
    }
};

class Student{
private:
    Person p;//student class creates an object of person,this object is member of student
    int roll_no;

public:
    void getData(){
    p.getData();
    cout<<"Enter roll No.:";
    cin>>roll_no;

    }
    void showData(){
    p.showData();
    cout<<"Roll NO.:"<<roll_no<<endl;
    }

};

int main()
{
    Student s;
    s.getData();
    s.showData();
    return 0;
}
