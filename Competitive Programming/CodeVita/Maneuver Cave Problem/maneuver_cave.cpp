#include <bits/stdc++.h>
using namespace std;

int calc(int n, int m) {
    if(n == 1 || m == 1)
        return 1;
    else
        return calc(n-1, m) + calc(n, m-1);
}

void solve() {
    int n = 0, m = 0;
    cin >> n >> m;
    cout << calc(n, m) << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 0;
    cin >> t;
    while(t--)
        solve();
}
