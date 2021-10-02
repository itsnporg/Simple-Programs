#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 0, ans = 0;
    cin >> n;
    while(pow(2,ans) <= n ) ans++;

    cout << ans << "\n";
}
