#include<iostream>
using namespace std;
string pytha(int A,int B,int C)
{
    int max,S,P;
    max=A>B?(A>C?A:C):(B>C?B:C);
    P=max*max;
    if(A!=max && B!=max)
    {
        S=A*A+B*B;
    }
    else if(B!=max && C!=max)
    {
        S=B*B+C*C;
    }
    else
    {
        S=C*C+A*A;
    }
    if(P==S)
    {
     return "it is pythagorian triplet";   
    }
    else
    {
        return "it is not a pythagorian triplet";
    }
}
int main()
{
    int x,y,z;
    cout<<"enter the value of x ,y and z :";
    cin>>x >>y >>z;
    cout<<pytha(x,y,z);
    return 0;
}
