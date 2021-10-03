#pragma GCC optimize ("Ofast")

#include <bits/stdc++.h>

#define endl    '\n'

using namespace std;

void Fast() {
    cin.sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

const int N = 20 + 9, M = 40 + 9, oo = 0x3f3f3f3f;

int Head[N], Next[M], To[M], dis[N], Cost[M], Par[N], Tea[N], ne, n, m, q, tax, pass;
string stations[N], u, v;
map <string, int> inv;

void addEdge(int from, int to, int cost)
{
    Next[++ne] = Head[from];
    To[ne] = to;
    Cost[ne] = cost;
    Head[from] = ne;
}

void Dijkstra(int src)
{
    memset(dis, 0x3f, sizeof dis);
    memset(Par, -1, sizeof Par);

    priority_queue <pair <int, int>,
                   vector <pair <int, int> >,
                   greater <pair <int, int> > > Q;

    Q.push({0, src});
    dis[src] = Tea[src];

    int node, cost;
    while(Q.size()) {
        tie(cost, node) = Q.top();
        Q.pop();

        for(int i = Head[node]; i; i = Next[i])
            if(dis[node] + Tea[To[i]] + Cost[i] < dis[To[i]]) {
                dis[To[i]] = dis[node] + Tea[To[i]] + Cost[i];
                Q.push({dis[To[i]], To[i]});
                Par[To[i]] = node;
            }
    }
}

long double profit(int a) {
    return ((long double)a * 0.1);
}

void _clear() {
    memset(Head, 0, sizeof Head);
    ne = 0;
    inv.clear();
}

void printPath(int a) {
    if(a == -1) return;

    printPath(Par[a]);
    if(Par[a] != -1) cout << " ";
    cout << stations[a];
}

void Solve() {
    _clear();

    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> stations[i] >> Tea[i];
        inv[stations[i]] = i;
    }

    cin >> m;
    while(m--) {
        cin >> u >> v >> tax;
        addEdge(inv[u], inv[v], tax << 1);
        addEdge(inv[v], inv[u], tax << 1);
    }

    cin >> q;
    for(int i = 1; i <= q; ++i) {
        cin >> u >> v >> pass;

        Dijkstra(inv[u]);

        cout << "Query #" << i << endl;
        printPath(inv[v]);

        cout << "\nEach passenger has to pay : ";
        cout << ((double)dis[inv[v]] + profit(dis[inv[v]])) / pass;
        cout << " taka" << endl;
    }
}

int main() 
{
    Fast();

    cout << fixed << setprecision(2);

    int tc = 1;
    cin >> tc;
    for(int i = 1; i <= tc; ++i) {
        if(i > 1) cout << endl;
        cout << "Map #" << i << endl;
        Solve();
    }
}

