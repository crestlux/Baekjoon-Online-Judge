#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int dx[] = { 0,0,-1,1 }, dy[] = { -1,1,0,0 };
bool visited[1001][1001][2];
class info {
public:
    int y = 0;
    int x = 0;
    int cost = 0;
    bool wall_dstr = false;
};
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M; vector<vector<int>> graph;
    cin >> N >> M;
    graph.resize(N, vector<int>(M, 0));
    cin.ignore();
    for (auto &e1 : graph) {
        for (auto &e2 : e1) {
            auto in = cin.get();
            e2 = in - '0';
        }
        cin.ignore();
    }
    queue<info> q;
    int ret = INT_MAX;
    auto bfs = [&](int x, int y) {
        visited[y][x][0] = true;
        q.push({ y,x, 1, false });
        while (!q.empty()) {
            int cy = q.front().y, cx = q.front().x, cost = q.front().cost;
            bool wall_dstr = q.front().wall_dstr;
            if (cy == N - 1 and cx == M - 1) {
                ret = min(cost, ret);
            }
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int ny = cy + dy[i], nx = cx + dx[i];
                if (ny < 0 or ny >= N or nx < 0 or nx >= M) continue;
                if (!visited[ny][nx][wall_dstr] and !graph[ny][nx]) {
                    visited[ny][nx][wall_dstr] = true;
                    q.push({ ny, nx, cost + 1, wall_dstr });
                }
                else if (!visited[ny][nx][true] and graph[ny][nx] and !wall_dstr) {
                    visited[ny][nx][true] = true;
                    q.push({ ny, nx, cost + 1, !wall_dstr });
                }
            }
        }
    };
    bfs(0, 0);
    if (ret == INT_MAX) ret = -1;
    cout << ret << "\n";
    return 0;
}