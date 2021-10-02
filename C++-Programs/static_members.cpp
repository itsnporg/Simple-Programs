#include <iostream>

using namespace std;
class Student{
private:
    int SN;
    static int count;
public:
    Student(){
    count++;
    SN=count;
    }
    void display(){
    cout<<"SN:"<<SN<<endl;
    }
    static void displayCount(){
    cout<<"Number of objects created:"<<count<<endl;
    }
};

int Student::count=0;

int main()
{
    Student s1,s2,s3,s4;
    s1.display();
    s2.display();
    s3.display();
    s4.display();
    Student::displayCount();
    return 0;
}
