#include <bits/stdc++.h>
using namespace std;

bool prime(int n) {
    int i;
    bool flag = false;
    for(i = 2; i <= n/2; i++) {
        if(n % i == 0)
            flag = true;
    }
    return flag;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 0, arr[25], sum = 0, count = 0, l = 0;
    bool c, cnt;
    cin >> n;
    for(int i = 2; i <= n; i++) {
        cnt = false;
        for(int j = 2; j <= n/2; j++) {
            if(i % j == 0) {
                cnt = true;
            }
        }
        if(cnt == false) {
            arr[l] = i;
            l++;
        }
    }
    for(int i = 0; i < l; i++) {
        sum += arr[i];
        c = prime(sum);
        if(c == true)
            count++;
    }
    cout << count << "\n";
}
