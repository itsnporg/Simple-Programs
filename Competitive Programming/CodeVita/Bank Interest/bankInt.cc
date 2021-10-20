#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int p = 0, y = 0;
	int B[2] = {};
	cin >> p >> y;
	for(int i = 0; i < 2; i++) {
		int s = 0;
		cin >> s;
		int sum = 0;
		for(int j = 0; j < s; j++) {
			float per = 0, r = 0, den = 0, emi = 0;
			cin >> per >> r;
			den = 1 - 1/ (pow(1+r, per*12));
			emi = (p*r)/den;
			sum += emi;
		}
		B[i] = sum;
	}
	if(B[0] < B[1]) cout << "Bank A\n";
	else cout <<"Bank B\n";
}
