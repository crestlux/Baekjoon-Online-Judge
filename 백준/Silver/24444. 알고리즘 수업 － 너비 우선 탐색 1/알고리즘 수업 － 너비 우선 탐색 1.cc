#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> v;
vector<bool> visited; vector<int> order;
queue<int> q;
int N, M, R;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M >> R;
    v.resize(N + 1); visited.resize(N + 1, false); order.resize(N + 1);
    for (int i = 0; i < M; ++i) {
        int p, q;
        cin >> p >> q;
        v[p].push_back(q);
        v[q].push_back(p);
    }
    for (auto &e : v)
        ranges::sort(e);
    int cnt = 1;
    auto bfs = [&](int x) {
        q.push(x);
        visited[x] = true;
        order[x] = cnt++;
        while (!q.empty()) {
            int c = q.front();
            q.pop();
            for (const auto &e : v[c]) {
                if (!visited[e]) {
                    visited[e] = true;
                    order[e] = cnt++;
                    q.push(e);
                }
            }
        }
    };
    bfs(R);
    for (int i = 0; const auto & e : order) {
        if (!i++) continue;
        cout << e << "\n";
    }
    return 0;
}