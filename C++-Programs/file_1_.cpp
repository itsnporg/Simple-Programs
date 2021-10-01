#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ofstream ofs("Textfile1.txt", ios::app); //app for append and trunc for truncate

    ofs << "Multiplication table of 5 : " << endl;

    for(int i = 1; i < 11;i++)
        ofs << 5 << " "<< "x " << i << " " <<"= "<< i * 5 << endl;

    ofs.close();
    cout << "Done :)"<<endl;
}