#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int N, M, curcnt, cnt = INT_MAX; vector<vector<int>> graph(9, vector<int>(9));
vector<pair<int, int>> cam[6]; vector<int> watch_type[6];
void mov(vector<vector<int>> &graph, int x, int y, int dir) {
    //up, down, left, right
    if (dir & (1 << 3)) { //up
        for (int i = y; i >= 0; i--) {
            if (graph[i][x] == 6) break;
            if (!graph[i][x]) graph[i][x] = -1;
        }
    }
    if (dir & (1 << 2)) { //down
        for (int i = y; i < N; i++) {
            if (graph[i][x] == 6) break;
            if (!graph[i][x]) graph[i][x] = -1;
        }
    }
    if (dir & (1 << 1)) { //left
        for (int i = x; i >= 0; i--) {
            if (graph[y][i] == 6) break;
            if (!graph[y][i]) graph[y][i] = -1;
        }
    }
    if (dir & (1 << 0)) { //right
        for (int i = x; i < M; i++) {
            if (graph[y][i] == 6) break;
            if (!graph[y][i]) graph[y][i] = -1;
        }
    }
}
void recsolve(vector<vector<int>> graph, int x, int y, int depth, const int &wc) { 
    // solve problem with recursive function
    bool coord_change = false;
    if (depth != 0) {
        mov(graph, x, y, watch_type[graph[y][x]][wc]);
        if (x + 1 == M) { x = 0; ++y; }
        else { ++x; }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!coord_change) { i = y; j = x; coord_change = true; }
            if (graph[i][j] >= 1 && graph[i][j] <= 4) {
                for (int wtcase = 0; wtcase < static_cast<int>(watch_type[graph[i][j]].size()); wtcase++) {
                    recsolve(graph, j, i, depth + 1, wtcase);
                }
            }
        }
    }
    curcnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (graph[i][j] == 0) curcnt++;
        }
    }
    cnt = min(cnt, curcnt);
    return;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    watch_type[1].insert(watch_type[1].end(), { 1,2,4,8 });
    watch_type[2].insert(watch_type[2].end(), { 3,12 });
    watch_type[3].insert(watch_type[3].end(), { 5,6,9,10 });
    watch_type[4].insert(watch_type[4].end(), { 7,11,13,14 });
    watch_type[5].insert(watch_type[5].end(), { 15 });
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> graph[i][j];
            if (graph[i][j] != 0 && graph[i][j] != 6) cam[graph[i][j]].push_back({ j, i });
        }
    }
    for (const auto &coord : cam[5]) {
        mov(graph, coord.first, coord.second, 15);
    }
    recsolve(graph, 0, 0, 0, 0);
    cout << cnt << "\n";
    return 0;
}