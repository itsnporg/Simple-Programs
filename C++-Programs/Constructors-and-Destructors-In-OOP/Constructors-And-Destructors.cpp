//C++ program to know about Constructor and Destructor in OOPS

//For detailed explanation kindly read markdown file on it.


#include<bits/stdc++.h>
using namespace std;

class student
{
    private://This make the data member private and are not accessible to the function outside the class.

        //Data Members
        string student_name;
        int student_rollnumber;
        string student_bloodgroup;
        long int student_mobnumber;
        string father_name;
    

    public:
        //Function Members:
        //Only this function can access the data members.
        //And this function is called by the class's object in the main function
        void setData(string stdname, int stdroll, string bloodgrp, long int mobno, string fthrname)//this function will help to set the data when called up in main function
        {
            student_name = stdname;
            student_rollnumber = stdroll;
            student_bloodgroup = bloodgrp;
            student_mobnumber = mobno;
            father_name = fthrname;

        }

        void displayData()//This function is used to display the student detail set by setData function, when called up by main function.
        {
            cout << "Student's name: " << student_name << endl;
            cout << "Student's roll number: " << student_rollnumber << endl;
            cout << "Student's blood group: " << student_bloodgroup << endl;
            cout << "Student's mobile number: " << student_mobnumber << endl;
            cout << "Student's father's name: " << father_name << endl;
            cout << endl << endl;
        }

        //Default Constuctors: Doesn't take any arguments and called automatically when an object is created;
        student()
        {

            cout << "Default Constructor is called" << endl;
            student_name = "Vicky";
            student_rollnumber = 46;
            student_bloodgroup = "O+";
            student_mobnumber = 9926663242;
            father_name = "Raghav Nag";

        }

        //Parameterised Constructor: Take arguments and work on only those function which are given arguments.
        student(string stdname, int stdroll, string bloodgrp, long int mobno, string fthrname)
        {
            cout << "Parameterized Constructor is called" << endl;
            student_name = stdname;
            student_rollnumber = stdroll;
            student_bloodgroup = bloodgrp;
            student_mobnumber = mobno;
            father_name = fthrname;

        }

        //Copy Constructor: It copies the data of another object.
        student(student &obj)
        {

            cout << "Copy Constructor is called" << endl;
            student_name = obj.student_name;
            student_rollnumber = obj.student_rollnumber;
            student_bloodgroup = obj.student_bloodgroup;
            student_mobnumber = obj.student_mobnumber;
            father_name = obj.father_name;

        }

        //Destructor: It will be called whenever an object ends. Since we have 7 objects in the main function therefore it will be called 7 times when we run the program.
        ~student()
        {
            cout << "Destructor is called" << endl;
        }
};

int main(int argc, char const *argv[])
{
    student s1, s2, s3, s4,s5;//This is the object of the class and will be used for the 4 students' details
    s1.setData("Kaushal", 21, "B+", 9329083112, "Roshan Das");//We have set the according to the arguments in the class as the function are in public therefore we can access them.
    s2.setData("Ryuk", 32, "A+", 6378583349, "Tony Stark");
    s3.setData("Virat" , 45, "A+", 7734329421, "Raj Mehta");
    s4.setData("Manveer", 25, "O+", 9876599453, "Arminder Singh");

    cout << "\n\n\n\t\t-------Student's Details--------\n\n\n";
    s1.displayData();//This will display details of the object s1
    s2.displayData();//This will display details of the object s2
    s3.displayData();//And so on...
    s4.displayData();

    //Default constructor example
    s5.displayData();//Called by Default constructor.

    //Parameterised constructor example
    student s6("Ranveer", 39, "B+", 6653849201, "Vijay Chauhan");//This is an object which call parameterised constructor by giving arguments.
    s6.displayData();

    //Copy constructor example
    student s7 = s1;//Copies the data of the s1 object
    s7.displayData();

    return 0;
}

