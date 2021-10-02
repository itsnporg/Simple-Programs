#include<iostream>
using namespace std;

int main(){

  //Declaring variables to store numbers
  int a,b,c;
  
  
  //Taking input from user
  cout<<"Enter Three numbers: "<<endl;
  cin>>a>>b>>c;
  
  //compare a is greater than b and c both or not
  if(a>b && a>c){
    cout<<a<<" is maximum"<<endl;
  }
  
  //comparing b is greater than c or not
  //comparision of b and a is already done in above if block 
  else if(b>c){
    cout<<b<<" is maximum"<<endl;
  }
  
  // if else if block not executed  means a and b both are less than c means
  else{
    cout<<c<<" is maximum"<<endl; 
  }
  
  //code executed successfully
  return 0;
}
