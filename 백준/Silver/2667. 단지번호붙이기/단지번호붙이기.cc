#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int dx[] = { 0,0, -1,1 }, dy[] = { -1,1,0,0 };
int graph[26][26];
bool visited[26][26];
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; vector<int> h;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            char c;
            cin >> c;
            graph[i][j] = c - '0';
        }
    }
    function<void(int, int)> dfs = [&](int y, int x) {
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i], nx = x + dx[i];
            if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
            if (!visited[ny][nx] && graph[ny][nx]) {
                visited[ny][nx] = true;
                ++h.back();
                dfs(ny, nx);
            }
        }
    };
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (graph[i][j] && !visited[i][j]) {
                visited[i][j] = true;
                h.push_back(1);
                dfs(i, j);
            }
        }
    }
    sort(h.begin(), h.end());
    cout << h.size() << "\n";
    for (const auto &e : h) {
        cout << e << "\n";
    }
    return 0;
}