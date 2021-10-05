#include <bits/stdc++.h>
using namespace std;

// Segment tree implementation. Supports point update and range query.
class segmentTree {
    int N;
    vector<int> tree;
public:
    void init(int _N) {
        N = _N;
        tree.assign(4 * N + 1, 0);
    }

    int merge(int left, int right) {
        return left + right;
    }
    
    void build(vector<int>& a, int node, int L, int R) {
        if(L == R) {
            if (L < N) {
                tree[node] = a[L];
            }
            return;
        }
        int M = (L + R) / 2;
        build(a, node * 2 + 1, L, M);
        build(a, node * 2 + 2, M + 1, R);
        tree[node] = merge(tree[node * 2 + 1], tree[node * 2 + 2]);
    }
    void build(vector<int>& a) {
        build(a, 0, 0, N - 1);
    }

    void update(int node, int L, int R, int pos, int val) {
        if(L == R) {
            tree[node] = val;
            return;
        }
        int M = (L + R) / 2;
        if(pos <= M) {
            update(node * 2 + 1, L, M, pos, val);
        } else {
            update(node * 2 + 2, M + 1, R, pos, val);
        }
        tree[node] = merge(tree[node * 2 + 1], tree[node * 2 + 2]);
    }
    void update(int pos, int val) {
        update(0, 0, N - 1, pos, val);
    }
    
    int query(int node, int lx, int rx, int L, int R) {
        if(R < lx || rx < L) 
            return 0;

        if(L <= lx && rx <= R) 
            return tree[node];

        int M = (lx + rx) / 2;
        int left = query(node * 2 + 1, lx, M, L, R);
        int right = query(node * 2 + 2, M + 1, rx, L, R);
        return merge(left, right);
    }
    int query(int l, int r) {
        return query(0, 0, N - 1, l, r);
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); 
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    segmentTree st;
    st.init(n);
    st.build(a);

    int queries;
    cin >> queries;
    while (queries--) {
        int type;
        cin >> type;
        // All indices are 0th based.
        if (type == 1) {
            // Type = 1, Update value.
            int index, val;
            cin >> index >> val;
            st.update(index, val);
        } else {
            // Type = 2, range query
            int l, r;
            cin >> l >> r; 
            cout << st.query(l, r) << '\n';
        }
    }

    return 0;
}


/*
Sample input: 
5
1 2 3 4 5
3
2 0 4
1 2 5
2 0 4

Sample uutput:
15
17

*/