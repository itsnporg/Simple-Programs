#include <iostream>
using namespace std;
/* scoping-- 3 levels in C++ 
1.global variable -- to use global use :: in front.
2.inside function function { ...... }
3.inside block { ...... }
*nearest block value is always used*/

int x = 5;
int main()
{
    int x= 6;
    {
        int x = 7;
        cout<<"Inside block "<<x<<endl;
    }
    cout<<"Inside main "<<x<<endl;
    cout<<"Global variable "<<::x<<endl;
    cout<<"Again inside main "<<x<<endl;
}