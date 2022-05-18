#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int dx[] = { 0,0,-1,1,-1,-1,1,1 }, dy[] = { -1,1,0,0,-1,1,-1,1 };
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    while (1) {
        int w, h, graph[51][51] = { 0, }; bool visited[51][51] = { 0, };
        int cnt = 0;
        cin >> w >> h;
        if (w == 0 && h == 0) break;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                cin >> graph[i][j];
            }
        }
        function<void(int, int)> dfs = [&](int y, int x) {
            for (int i = 0; i < 8; ++i) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
                if (!visited[ny][nx] && graph[ny][nx]) {
                    visited[ny][nx] = true;
                    dfs(ny, nx);
                }
            }
        };
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (!visited[i][j] && graph[i][j]) {
                    visited[i][j] = true;
                    dfs(i, j);
                    ++cnt;
                }
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}