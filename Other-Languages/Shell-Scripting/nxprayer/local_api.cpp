#include <iostream>
#include <set>
#include <string>
#include <assert.h>
#include <utility>

#if __cplusplus >= 201402L
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#endif

#if __cplusplus >= 201402L
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#endif

using namespace std;

template <class T, typename Comp = less <T> >
using indexed_set = tree <T, null_type, Comp, rb_tree_tag, tree_order_statistics_node_update>;

void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
}

void file() {
  freopen("/tmp/nxprayer/input", "r", stdin);
  freopen("/tmp/nxprayer/output", "w", stdout);
}

class compare {
  public:
  bool operator() (const pair <string, string> &lhs, const pair <string, string> &rhs) const {
    if(lhs.second != rhs.second)
      return lhs.second < rhs.second;
    else
      return lhs.first < rhs.first;
  }
};

const int TEN = 10;

indexed_set <pair<string, string>, compare> mawaqeet;
string sf, ss;
int cur_inx = -1;
pair <string, string> cur, nxt;

pair <string, string> next_prayer() {
  return *mawaqeet.find_by_order(((int)mawaqeet.order_of_key(cur) + 1) % 9);
}

bool adhan_now() {
  return (cur.second == nxt.second);
}

bool fetch_next() {
  return (cur.second == "00:00");
}

pair <int, int> converto_int(string &x) {
  assert((int)x.size() == 5);
  int hrs = (x[0] - '0') * TEN + (x[1] - '0');
  int mns = (x[3] - '0') * TEN + (x[4] - '0');

  return make_pair(hrs, mns);
}

string difference() {
  string ret = "";

  int chrs, cmns, nhrs, nmns, rhrs, rmns;
  tie(chrs, cmns) = converto_int(cur.second);
  tie(nhrs, nmns) = converto_int(nxt.second);

  if(chrs > nhrs) nhrs += 24;
  if(cmns > nmns) nmns += 60, --nhrs;

  rhrs = nhrs - chrs;
  rmns = nmns - cmns;

  if(rhrs < 10) ret += "0";
  ret += to_string(rhrs);
  ret += ":";
  if(rmns < 10) ret += "0";
  ret += to_string(rmns);

  return ret;
}

void read_data() {
  while(cin >> ss >> sf) {
    mawaqeet.insert(make_pair(sf, ss));

    if(sf == "A")
      cur = make_pair(sf, ss);
  }
}

int main () {
  fast();
  file();

  read_data();
  nxt = next_prayer();

  cout << "nxprayer " <<  nxt.first << " " << nxt.second << endl;
  cout << "remains " << difference() << endl;
  cout << "adhantime " << adhan_now() << endl;
  cout << "fetchnextday " << fetch_next() << endl;
}
