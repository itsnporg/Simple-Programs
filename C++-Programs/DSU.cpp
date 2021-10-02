#include <bits/stdc++.h>
using namespace std;

// DSU implementation with path compression and union by rank
class DSU {
    vector<int> par;

public:
    void init(int n) {
        par.assign(n + 1, -1);
    }

    int getParent(int a) {
        if(par[a] < 0) {
            return a;
        }
        return par[a] = getParent(par[a]);
    }

    void Union(int node1, int node2) {
        node1 = getParent(node1);
        node2 = getParent(node2);
        if(node1 != node2){
            if(par[node1] > par[node2]) {
                swap(node1, node2);
            }
            par[node1] += par[node2];
            par[node2] = node1;
        }
    }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); 
    int n;
    cin >> n;
    int queries;
    cin >> queries;

    DSU ds;
    ds.init(n);
    // Two type of query,
    // first put a edge between node "a" and "b".
    // second check if given two nodes "a" and "b" is in same component or not.
    while(queries--) {
        int type;
        cin >> type;
        int a, b;
        cin >> a >> b;
        
        if (type == 1) {
            ds.Union(a, b);
        } else {
            cout << (ds.getParent(a) == ds.getParent(b) ? "YES\n": "NO\n");
        }
    }
}

/*
Sample input:
4 4
1 1 2
1 1 3
2 1 4
2 2 3

Sample output:
NO
YES
*/
