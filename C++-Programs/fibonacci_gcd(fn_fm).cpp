#include <bits/stdc++.h>
#include <map>
using namespace std;
#define long long long
const long M = 1000000007;
map<long, long> F;
long f(long n)
{
	if (F.count(n))
		return F[n];
	long k = n / 2;
	if (n % 2 == 0)
	{
		return F[n] = (f(k) * f(k) + f(k - 1) * f(k - 1)) % M;
	}
	else
	{
		return F[n] = (f(k) * f(k + 1) + f(k - 1) * f(k)) % M;
	}
}
long gcd(long a, long b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}
int main()
{
	long n, m;
	F[0] = F[1] = 1;
	cin >> n >> m;
	cout << f(gcd(n, m) - 1);

	return 0;
}