#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n = 0, i = 0, j = 0, x = 0, sum = 0, k = 0, time = 0;

    cin >> n;
    int arr[n] = {}, ans[n] = {};
    for(i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    for(i = 0; i < n; i++) {
        sum += arr[i];
        ans[x] = sum;
        x++;
    }
    for(i = 1; i < x; i++) {
        time += ans[i];
    }

    cout << time << "\n";

}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}
