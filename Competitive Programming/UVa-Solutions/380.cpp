#pragma  GCC optimize ("Ofast")

#include <bits/stdc++.h>

#define  endl                '\n'

using namespace std;

void Fast() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

/**----------------->>  Quality Over Quantity  <<----------------**/

const int dx[] = {-1, -1, +1, +1, -2, -2, +2, +2};
const int dy[] = {-2, +2, -2, +2, -1, +1, -1, +1}, oo = 0x3f3f3f3f;
int id, board[10][10], movs, dis[10][10];
char grid[505][505], si, sj, ti, tj;
string line;
stringstream ss;


bool valid(int r, int c) {
    return r >= 1 && r <= 8 && c >= 1 && c <= 8 && dis[r][c] == oo;
}

void BFS(int sr, int sc) {
    memset(dis, 0x3f, sizeof dis);
    queue <array <int, 2>> Q;
    Q.push({sr, sc});
    dis[sr][sc] = 0;

    array <int, 2> cell;
    int r, c;
    while(Q.size()) {
        cell = Q.front(); Q.pop();
        for(int i = 0; i < 8; ++i)
        {
            r = cell[0] + dx[i];
            c = cell[1] + dy[i];
            if(!valid(r, c)) continue;
            dis[r][c] = dis[cell[0]][cell[1]] + 1;
            Q.push({r, c});
        }
    }
}

void Solve() {
    BFS((int)si, (int)sj);
    cout << dis[ti][tj];
}

void MultiTest(bool Tests = 0)
{
    int tc = 1; (Tests) && (cin >> tc);
    for(int i = 1; getline(cin, line) && line.size(); ++i) {
        ss.clear();
        ss.str(line);
        ss >> si >> sj >> ti >> tj;

        cout << "To get from " << si << sj << " to " << ti << tj << " takes ";
        si -= 96;
        sj -= 48;
        ti -= 96;
        tj -= 48;

        Solve();
        cout << " knight moves." << endl;
    }
}

/**------------------------->>  Main  <<-------------------------**/

int main()
{
    Fast(); File(); MultiTest();
}

