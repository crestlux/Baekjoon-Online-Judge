#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, a, b, ret = INT_MAX;
    queue<pair<int, int>> q; bitset<10001> visited;
    cin >> N;
    vector<int> g(N + 1);
    for (int i = 1; i <= N; ++i) cin >> g[i];
    cin >> a >> b;
    auto bfs = [&](int idx) {
        visited[idx] = true;
        q.push({ idx,0 });
        while (!q.empty()) {
            int c = q.front().first, cnt = q.front().second;
            q.pop();
            if (b == c) ret = min(cnt, ret);
            for (int i = c % g[c]; i <= N; i += g[c]) {
                if (i > 0 and !visited[i]) {
                    visited[i] = true;
                    q.push({ i, cnt + 1 });
                }
            }
        }
    };
    bfs(a);
    ret == INT_MAX ? cout << "-1\n" : cout << ret << "\n";
    return 0;
}