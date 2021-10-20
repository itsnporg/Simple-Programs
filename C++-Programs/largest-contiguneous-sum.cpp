
////kaden's algorithm
#include<iostream>
using namespace std;
int MaxSumSubArray(int a[],int size){
int mmaxsum=INT_MIN;
int currsum=0;
for(int i=0;i<size;i++){
currsum=currsum+a[i];
if(currsum>mmaxsum){
    mmaxsum=currsum;
}
if(currsum<0){
  currsum=0;
}
}
return mmaxsum;
}

int main(){

    int array[6]={1,-2,3,-4,5,6};
    cout<<"Largest Contiguous sum in the array is : ";
    cout<<MaxSumSubArray(array,6);
    return 0;
}
