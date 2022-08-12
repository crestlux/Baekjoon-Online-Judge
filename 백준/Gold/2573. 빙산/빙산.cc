#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int dx[] = { 0,0,-1,1 }, dy[] = { -1,1,0,0 };
bool visited[301][301];
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M, ret = 0; vector<vector<int>> graph, tmp;
    cin >> N >> M;
    graph.resize(N, vector<int>(M));
    tmp.resize(N, vector<int>(M));
    for (auto &e1 : graph) {
        for (auto &e2 : e1) {
            cin >> e2;
        }
    }
    tmp = graph;
    function<void(int, int)> dfs_melt = [&](int y, int x) {
        visited[y][x] = true;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 or nx >= M or ny < 0 or ny >= N) continue;
            if (!visited[ny][nx] and graph[ny][nx]) {
                int cnt = 0;
                for (int j = 0; j < 4; ++j) {
                    int nnx = nx + dx[j], nny = ny + dy[j];
                    if (nnx < 0 or nnx >= M or nny < 0 or nny >= N) continue;
                    if (!graph[nny][nnx]) ++cnt;
                }
                tmp[ny][nx] = max(tmp[ny][nx] - cnt, 0);
                dfs_melt(ny, nx);
            }
        }
    };
    auto is_separated = [&]() -> bool {
        int cnt = 0;
        function<void(int, int)> dfs = [&](int y, int x) {
            visited[y][x] = true;
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 or nx >= M or ny < 0 or ny >= N) continue;
                if (!visited[ny][nx] and graph[ny][nx]) {
                    dfs(ny, nx);
                }
            }
        };
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (!visited[i][j] and graph[i][j]) {
                    ++cnt;
                    dfs(i, j);
                }
            }
        }
        return (cnt > 1);
    };
    auto melted_all = [&]() -> bool {
        bool b = true;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (graph[i][j]) b = false;
            }
        }
        if (b) ret = 0;
        return b;
    };
    while (1) {
        if (melted_all() or is_separated()) break;
        ++ret;
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (!visited[i][j] and graph[i][j]) {
                    int cnt = 0;
                    for (int k = 0; k < 4; ++k) {
                        int nnx = j + dx[k], nny = i + dy[k];
                        if (nnx < 0 or nnx >= M or nny < 0 or nny >= N) continue;
                        if (!graph[nny][nnx]) ++cnt;
                    }
                    tmp[i][j] = max(tmp[i][j] - cnt, 0);
                    dfs_melt(i, j);
                    graph = tmp;
                }
            }
        }
    }
    cout << ret << "\n";
    return 0;
}