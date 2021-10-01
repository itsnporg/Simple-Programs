#include <iostream>
using namespace std;

int main(){
    char a[] = "decimals";
    char b[] = "medicals";
    int i, H[26]={0};

    cout << a << " and " << b << " is ";

    for (i = 0;a[i]!='\0';i++) {//to iterate through 1st string
        H[a[i] - 97] += 1; //to increment in array if found
    } 

    for (i = 0; b[i]!='\0'; i++)
    {
        H[b[i] - 97] -= 1;
        if(H[b[i]-97]<0){ // decrement in array if found
            cout << "not anagram" << endl;
            break;
        }
    }
        if(b[i]=='\0') {//if all equivalent
            cout << "an anagram" << endl;
        }
}