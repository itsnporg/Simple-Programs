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

const int N = 1e5 + 9, M = 2e5 + 9, oo = 0x3f3f3f3f;
ll INF = 0x3f3f3f3f3f3f3f3f;

int Head[N], Par[N], Next[M], To[M], Cost[M], ne, n, k, u, v, st, tr, tax;
ll dis[N];

int T[10];
bool seen[6 * 110];

void addEdge(int from, int to, int cost)
{
    Next[++ne] = Head[from];
    To[ne] = to;
    Cost[ne] = cost;
    Head[from] = ne;
}

priority_queue <pair <ll, int>,
                   vector <pair <ll, int> >,
                   greater <pair <ll, int> > > Q;

void Dijkstra()
{
    int node;
    ll cost;
    while(Q.size())
    {
        tie(cost, node) = Q.top(); Q.pop();
        if(cost != dis[node]) continue;

        for(int i = Head[node]; i; i = Next[i]) if(dis[node] + Cost[i] < dis[To[i]]) {
            dis[To[i]] = dis[node] + Cost[i];
            Q.push({dis[To[i]], To[i]});
        }
    }
}

vector <int> restorePath(int dest)
{
    vector <int> path;
    if(dis[dest] == INF) return path;

    for(int i = dest; ~i; i = Par[i])
        path.push_back(i);

    reverse(path.begin(), path.end());
    return path;
}

void _clear() {
    memset(Head, 0, sizeof Head);
    memset(seen, false, sizeof seen);
    ne = 0;
}

stringstream ss;
string line;

void Solve()
{
    _clear(); ++k;

    for(int i = 1; i <= n; ++i)
        cin >> T[i];

    cin.ignore();
    int id = 1;

    for(int i = 1; i <= n; ++i)
    {
        ss.clear(); getline(cin, line); ss.str(line);

        ss >> u; u += id;
        seen[u] = true;

        while(ss >> v)
        {
            v += id;
            seen[v] = true;

            addEdge(u, v, (v - u) * T[i]);
            addEdge(v, u, (v - u) * T[i]);

            u = v;
        }
        id += 100;
    }

    for(int i = 2; i <= 500; ++i)
    for(int j = i + 100; j <= 500; j += 100)
        if(seen[j])
        {
            addEdge(i, j, 60);
            addEdge(j, i, 60);
        }

    memset(dis, 0x3f, sizeof dis);
    dis[1] = dis[101] = dis[201] = dis[301] = dis[401] = 0;

    Q.push({0, 1});
    Q.push({0, 101});
    Q.push({0, 201});
    Q.push({0, 301});
    Q.push({0, 401});

    Dijkstra();

    for(int i = 100; i <= 500; i += 100) if(dis[k + i] < dis[k])
        dis[k] = dis[k + i];

    if(dis[k] == INF)
        cout << "IMPOSSIBLE" << endl;
    else
        cout << dis[k] << endl;

}

int main()
{
    Fast();

    int tc = 1;
    for(int i = 1; cin >> n >> k; ++i)
        Solve();
}
