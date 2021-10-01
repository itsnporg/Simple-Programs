#include <iostream>
using namespace std;
template <typename A>

A & magic (A &a){ //return by refrence function
    return a;
}

int main(){
    //first input
    double n;
    cout << "Enter a number : ";
    cin >> n;

    magic(n); //calling function
    cout << "After call : " <<endl<<endl;
    magic(n) = 100.234; //changing value of variable -refrencing
    cout << "After call changing value from main : " <<n<<endl<<endl; //checking value after refrencing
    //second input
    cout << "Enter next number : "; 
    int k;
    cin >> k; 
    magic(k) = 25.5; //changing value
    cout <<"Changes in main : " << k << endl; //checking after changing
}