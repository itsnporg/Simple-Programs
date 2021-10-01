#include <iostream>
using namespace std;

int division(int a,int b){
    if(b == 0)
        throw 0;
    return a / b;
}
int main()
{
    int x, y,result;
    cout << "Enter 2 number in form [a/b separated by space] : ";
    cin >> x >> y;
    try{
        result = division(x, y);
        cout << "Result of division is : " << result << endl;
    }

    catch(int p){
            cout<<"Division failed" << endl;
            cout << "Division by " << p << endl;
    }
    cout << "Okay! However, Prorgam terminates. Bye :)" << endl;
}