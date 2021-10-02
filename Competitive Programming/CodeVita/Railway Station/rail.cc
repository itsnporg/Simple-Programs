#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 0, arrive = 0, stop = 0, platform = 1, ans = 1;
    cin >> n;
    int a[n] = {}, b[n] = {};
    for(int i = 0; i < n; i++) {
        cin >> arrive >> stop;
        a[i] = arrive;
        b[i] = arrive + stop;
    }

    sort(a, a + n);
    sort(b, b + n);

    for(int i = 1; i < n; i++) {
        if(a[i] <= b[i+1]) {
            platform++;
            i++;
        }
        else if(a[i] > b[i+1]) {
            platform--;
            i++;
        }
        ans = max(ans, platform);
    }
    cout << ans << "\n";
}
