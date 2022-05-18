#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int dx[] = { 0,0,-1,1 }, dy[] = { -1,1,0,0 };
char graph[101][101]; bool visited[101][101];
int ca_cnt = 0, nca_cnt = 0;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> graph[i][j];
        }
    }
    function<void(const int, const int, const char, const bool)> dfs = [&](const int &y, const int &x, const char &color, const bool &ca) {
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (ca) {
                if (!visited[ny][nx]) {
                    if ((color == 'G' || color == 'R') && graph[ny][nx] != 'B') {
                        visited[ny][nx] = true;
                        dfs(ny, nx, graph[ny][nx], true);
                    }
                    else if (color == 'B' && graph[ny][nx] == 'B') {
                        visited[ny][nx] = true;
                        dfs(ny, nx, graph[ny][nx], true);
                    }
                }
            }
            else {
                if (!visited[ny][nx] && graph[ny][nx] == color) {
                    visited[ny][nx] = true;
                    dfs(ny, nx, graph[ny][nx], false);
                }
            }
        }
    };
    for (int c = 0; c < 2; ++c) {
        int ca = c;
        memset(visited, false, sizeof(visited));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (!visited[i][j]) {
                    visited[i][j] = true;
                    if (!ca) {
                        ++nca_cnt;
                        dfs(i, j, graph[i][j], false);
                    }
                    else {
                        ++ca_cnt;
                        dfs(i, j, graph[i][j], true);
                    }
                }
            }
        }
    }
    cout << nca_cnt << " " << ca_cnt << "\n";
    return 0;
}