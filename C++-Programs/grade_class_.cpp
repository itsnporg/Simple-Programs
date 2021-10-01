#include <iostream>
using namespace std;

class student 
{
    private:
        int roll,maths, comp, eng;
        string name;

    public:
        student(int r, string n, int m, int c, int e);

        inline int total();

        char grade(){
                float avg = total() / 3;
            if (avg > 60)
                return 'A';
            else if (avg < 60 && avg >=40)
                return 'B';
            else
                return 'C';
        }
};

int main(){
    int roll;
    string name;
    int m, c, e;
    cout << "Enter Roll : ";
    cin >> roll;
    cout << "Name of student : ";
    cin >> name;
    cout << "Marks in 3 subjects : ";
    cin >> m>>c>>e;
    student stud(roll, name, m, c, e);
    cout<<"Total marks: "<<stud.total()<<endl;
    cout << "Grade for student: " << stud.grade() << endl;
}

student :: student (int r, string n,int m, int c, int e)
    {
            roll = r;
            name = n;
            maths = m;
            comp = c;
            eng = e; 
    }

int student ::total(){
    return (maths + comp + eng);
}
