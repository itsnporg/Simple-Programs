#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 0;
    cin >> n;
    if(n < 0 || n > 1000) exit(1);
    
    int one = 0, two = 0, five = ((n-4)/5);
    if(((n - 5 * five) % 2) == 0) {
        one = 2;
    }
    else {
        one = 1;
    }
    two = (n - 5 * five - one) / 2;
    cout << (one + two + five) << " " << five << " " << two << " " << one << "\n";
}
