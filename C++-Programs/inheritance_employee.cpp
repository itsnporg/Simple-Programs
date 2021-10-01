#include <iostream>
using namespace std;

class Employee
{
    private:
        int eid;
        string name;
    public: 
        Employee(int e,string n){
            name = n;
            eid = e;
        }
        string getName() { return name; }
        int getEmployeeID() { return eid; }
};  // parent class

//derived classes
class FulltimeEmployee: public Employee
{
    private:
        int salary;
    public:
        FulltimeEmployee(int e,string n,int s):Employee(e,n)
        {
            salary = s;
        }
        int getSalary() { return salary; }
};

//2nd derived class
class ParttimeEmployee: public Employee{
    private:
        int wage;
    public:
        ParttimeEmployee(int e,string n,int w):Employee(e,n){
            wage = w;
        }
        int getWage() { return wage; }
};

int main(){
    ParttimeEmployee P1(1, "Nisham", 8000);
    FulltimeEmployee P2(2, "TheNisham", 90000);

    cout << "Daily wage of " << P1.getName() << " is " << P1.getWage() << endl;
    cout << "Salary of " << P2.getName() << " is " << P2.getSalary() << endl;
}