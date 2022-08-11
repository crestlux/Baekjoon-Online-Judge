#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> v; vector<int> order;
bitset<100001> visited;
queue<int> q;
int N, M, R;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M >> R;
    v.resize(N + 1); order.resize(N + 1);
    for (int i = 0; i < M; ++i) {
        int p, q;
        cin >> p >> q;
        v[p].emplace_back(q);
        v[q].emplace_back(p);
    }
    for (auto &e : v)
        ranges::sort(e);
    int cnt = 1;
    auto bfs = [&](int x) {
        q.emplace(x);
        visited[x] = true;
        order[x] = cnt++;
        while (!q.empty()) {
            int c = q.front();
            q.pop();
            for (const auto &e : v[c]) {
                if (!visited[e]) {
                    visited[e] = true;
                    order[e] = cnt++;
                    q.emplace(e);
                }
            }
        }
    };
    bfs(R);
    for (int i = 1; i <= N; ++i) {
        cout << order[i] << "\n";
    }
    return 0;
}