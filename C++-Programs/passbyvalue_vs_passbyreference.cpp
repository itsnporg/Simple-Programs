#include<iostream>
using namespace std;

void passByvalue_swap(int a,int b){

int temp=a;
a=b;
b=temp;

}

void passByReference_swap(int &a,int &b){

int temp=a;
a=b;
b=temp;

}

int main(){
    int a=2,b=5;
cout<<"Before swapping \n";
cout<<"a :"<<" "<<a<<endl;
cout<<"b :"<<" "<<b<<endl;
/////////////////////////////
passByvalue_swap(a,b);
cout<<"After swapping passByvalue_swap \n";
cout<<"a :"<<" "<<a<<endl;
cout<<"b :"<<" "<<b<<endl;
////////////////////////////////////
cout<<"After swapping passByReference_swap \n";
passByReference_swap(a,b);
cout<<"a :"<<" "<<a<<endl;
cout<<"b :"<<" "<<b<<endl;

    return 0;
}
