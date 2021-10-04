#include<iostream>
using namespace std;

int main() {

    int n;
    cout<<"Enter n: ";
    cin>>n;


// //  METHOD 1
//     for(int i=1; i<=n; i++){
//         for(int j=1; j<=n-i; j++){
//             cout<<"  ";
//         }
//         for(int j=1; j<=i; j++){
//             cout<<"* ";
//         }
//         for(int j=2; j<=i; j++){
//             cout<<"* ";
//         }
//         cout<<endl;
//     }
//     for(int i=n; i>=1; i--){
//         for(int j=1; j<=n-i; j++){
//             cout<<"  ";
//         }
//         for(int j=1; j<=i; j++){
//             cout<<"* ";
//         }
//         for(int j=2; j<=i; j++){
//             cout<<"* ";
//         }
//         cout<<endl;
//     }


//  METHOD 2
for(int i=1; i<=n; i++){
    for(int j=1; j<=n-i; j++){
        cout<<"  ";
    }
    for(int j=1; j<=2*i-1; j++){
        cout<<"* ";
    }
    cout<<endl;
}
for(int i=n; i>=1; i--){
    for(int j=1; j<=n-i; j++){
        cout<<"  ";
    }
    for(int j=1; j<=2*i-1; j++){
        cout<<"* ";
    }
    cout<<endl;
}
    return 0;
}