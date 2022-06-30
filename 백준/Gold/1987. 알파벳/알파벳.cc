#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int dx[] = { 0,0,-1,1 }, dy[] = { -1,1,0,0 };
bool visited[21][21], alph[26];
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int R, C, ret = 0;
    cin >> R >> C;
    vector<vector<char>> graph(R, vector<char>(C));
    for (auto &e1 : graph) {
        for (auto &e2 : e1) {
            cin >> e2;
        }
    }
    function<void(const int, const int, int)> dfs = [&](const int &y, const int &x, int cnt) {
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= C || ny < 0 || ny >= R || visited[ny][nx] || alph[graph[ny][nx] - 'A']) continue;
            else {
                auto &next = graph[ny][nx];
                visited[ny][nx] = true, alph[next - 'A'] = true;
                dfs(ny, nx, cnt + 1);
            }
        }
        ret = max(ret, cnt);
        visited[y][x] = false, alph[graph[y][x] - 'A'] = false;
    };
    visited[0][0] = true, alph[graph[0][0] - 'A'] = true;
    dfs(0, 0, 0);
    cout << ret + 1 << "\n";
    return 0;
}