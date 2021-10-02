#include <bits/stdc++.h>
using namespace std;

#define lli long long int

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 0, w = 0, h = 0, t = 0, f = 0, th = 0;
    cin >> n >> w >> h >> t >> f >> th;
    if(n > 100) exit(1);
    
    int i = 0, j = 0, k = 0, l = 0, s1 = 0, s2 = 0, s5 = 0, s10 = 0;
    int c = 0;
    for(i = 0; i < h; i++) {
        s1 = i * 100;
        if(s1 == w && i <= n && i > c) c = i;
        if(s1 < w) 
            for(j = 0; j <= t; j++) {
                s2 = s1 + j*200;
                if(s1 == w && (i+j) <= n && (i+j) > c) c = j+i;
                if(s2 < w) 
                    for(k = 0; k <= f; k++) {
                        s5 = s1 + k*500;
                        if(s5 == w && (i+j+k) <= n && (i+j+k) > c) c = i+j+k;
                        if(s5 < w)
                            for(l = 0; l <= th; l++) {
                                s10 = s5 + l * 1000;
                                if(s10 == w && (i+j+k+l) <= n && (i+j+k+l) > c) c = i+j+k+l;
                                if(s10 > w) l = th+1; 
                            }
                    }
            }
    }
    cout << c << "\n";
}
