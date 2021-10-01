#include <iostream>
using namespace std;
#define I int

I sum (I a=0,I b=0, I c=0){
    return a > b && a > c ? a : (b > c ? b : c);
}

I main () {
    cout << "Greatest Number is : \n";
    cout<<sum(10)<<endl;
    cout<<sum(10, 13, 252)<<endl;
    cout<<sum(345, 23)<<endl;
    return 0;
}