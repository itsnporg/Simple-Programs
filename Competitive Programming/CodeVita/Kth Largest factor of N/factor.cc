#include <bits/stdc++.h>
using namespace std;

#define lli long long int

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    lli n = 0, k = 0, i = 0, x = 0;
    vector<lli> arr;
    scanf("%lld,%lld", &n, &k);

    for(i = 1; i <= n; i++) {
        if(n % i == 0)
            arr.push_back(i);
    }
    x = arr.size();
    if(k > x) {
        cout << 1 << "\n";
    }
    else {
        cout << arr[x-k] << "\n";
    }
}
