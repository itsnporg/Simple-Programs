#include <bits/stdc++.h>
#define ln "\n"
#define ll long long int
#define vll vector<ll>
#define mod 1000000007
#define all(c) c.begin(), c.end()
using namespace std;

void solve()
{
 
    ll n;
    cin >> n; // for which number you want the factorial
    vll v; //declaring a vector to store a number in reverse order 
    v.push_back(1);
    for (ll i = 2; i <= n; i++)
    {
        ll carry = 0;
        for (ll j = 0; j < v.size(); j++)
        {
            ll temp = v[j] * i + carry;
            v[j] = temp % 10;
            carry = temp / 10;
        }
       // push carry to end of the vector
        while (carry)
        {
            v.push_back(carry % 10);
            carry /= 10;
        }
    }
  
   // as the number are stored in end to begin, we  have to print in this manner
    for (auto i = v.rbegin(); i != v.rend(); i++)
    {
        cout <<*i;
    }
    cout << ln;
    // v.clear();
 
}

int main()
{
    std::ios::sync_with_stdio(false);
    ll T =1;
	
    // cin >> T; // N test cases  remove comment 

    while (T--)
    {
        solve();
    }
    return 0;
}
