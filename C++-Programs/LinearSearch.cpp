// Searching

// Searching is the process of finding some particular element in the list. If the element is present in the list, then the process is called successful and the process returns the location of that element, otherwise the search is called unsuccessful.

// Linear Search

// Linear search is a sequential searching algorithm where we start from one end and check every element of the list until the desired element is found. It is the simplest searching algorithm.

// Linear Search Code in C++

#include<iostream>
using namespace std;

int linear(int[],int,int);//Function Declaration
int main()
{
int ar[50],size,item,i,pos;
cout<<"Enter number of elements=";
cin>>size;
cout<<"Enter Array's Elements=";
for(i=0;i<size;i++)
cin>>ar[i];
cout<<"Enter element which to be searched=";
cin>>item;
pos=linear(ar,size,item);
if(pos==-1)
cout<<"Element not Found";
else
cout<<"Element Found at="<<(pos+1);

return 0;
}
int linear(int ar[],int size,int item)//Function to perform linear search
{
int i;
for(i=0;i<size;i++)
{
    if(ar[i]==item)
    return i;
}    

return -1;

}

