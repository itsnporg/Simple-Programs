#include<iostream>
using namespace std;

long long int factorial(long long int a){
 if(a==1||a==0){
     return 1;
 }else{
     return a*factorial(a-1);
 }
 }

int main(){
  long long int n;
  cout<<" Enter your number \n ";
  cin>>n;
  cout<<"Factorial of "<<n <<" is: "<<factorial(n)<<"\n";
    return 0;
}
