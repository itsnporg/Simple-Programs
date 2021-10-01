#include <iostream>
using namespace std;
template<class A>
/* We can't return the address of local variable from a function as it gets destroyed with
the function, so to eliminate this problem we use pointer function to return value 
creating a memory in heap using new <datatype>[size] tag , which value can now be
returned*/
//"HEAP MEMORY" is global to program and can be accessed anywhere.

A *function(A n){
    A *p = new A[n];
    for (int i = 0; i < n;i++)
        p[i] = (i+1)*5;
    return p;
}

int main(){
    int *ptr = function(6);

    for (int i = 0; i < 6;i++)
        cout << *(ptr+i) << endl;
}