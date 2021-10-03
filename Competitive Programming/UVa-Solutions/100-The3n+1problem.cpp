#pragma GCC optimize ("Ofast")

#include <bits/stdc++.h>

#define endl      '\n'

using namespace std;

typedef int64_t    ll;
typedef __int128 i128;

void Fast() {
  cin.sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
}

/**---------------------->>  Constants  <<-----------------------**/

const int dx[] = { 1, -1, 0, 0, 1, 1, -1, -1 };
const int dy[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
const char dir[] = {'D', 'U', 'R', 'L'};
const long double eps = 1e-9, Pi = 2 * acos(0.0), Euler = 2.71828182845904523536;

const int N = 1e6 + 9, M = 1e6 + 9, oo = 0x3f3f3f3f, Mod = 1e9 + 7;

/**----------------->>  Quality Over Quantity  <<----------------**/

int l, r, ns, pg, next_smaller[N], prev_greater[N], dp[N];
stack <int> st;

ll bla(ll n)
{
  if(n == 1) return dp[1] = 1;
  if(n < N && ~dp[n]) return dp[n];

  ll res;
  if(n & 1ll)
    res = 1 + bla(3 * n + 1);
  else
    res = 1 + bla(n / 2);

  if(n < N)
    return dp[n] = res;
  return res;
}

void Solve()
{
  cin >> l >> r;

  if(l > r) swap(l, r);
  ns = next_smaller[l];
  pg = prev_greater[r];

  if(ns > r || ns == -1) ns = l;
  else
    for(int i = next_smaller[ns]; ~i && i <= r; i = next_smaller[i])
      if(dp[i] < dp[ns]) ns = i;

  if(pg < l || pg == -1) pg = r;
  else
    for(int i = prev_greater[pg]; ~i && i >= l; i = prev_greater[i])
      if(dp[i] > dp[pg]) pg = i;

  cout << ns << " " << pg << endl;
}

int main()
{
  Fast();

  memset(dp, -1, sizeof dp);
  for(int i = 2; i <= 1000000; ++i)
    bla(i);

  for(int i = 1000000; i; --i) {
    while(st.size() && dp[st.top()] >= dp[i])
      st.pop();

    if(st.empty())
      next_smaller[i] = -1;
    else
      next_smaller[i] = st.top();

    st.push(i);
  }

  st = stack <int> ();
  for(int i = 1; i <= 1000000; ++i) {
    while(st.size() && dp[st.top()] <= dp[i])
      st.pop();

    if(st.empty())
      prev_greater[i] = -1;
    else
      prev_greater[i] = st.top();

    st.push(i);
  }

  int tc = 1; cin >> tc;
  for(int i = 1; i <= tc; ++i) Solve();
}
