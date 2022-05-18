#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
vector<int> v[32001];
vector<bool> visited;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M; vector<int> ret;
    cin >> N >> M;
    visited.resize(N + 1);
    for (int i = 0; i < M; ++i) {
        int p, q;
        cin >> p >> q;
        v[p].push_back(q);
    }
    function<void(int)> dfs = [&](int x) {
        for (const auto &e : v[x]) {
            if (!visited[e]) {
                visited[e] = true;
                dfs(e);
            }
        }
        ret.push_back(x);
    };
    for (int i = 1; i <= N; ++i) {
        if (!visited[i]) {
            visited[i] = true;
            dfs(i);
        }
    }
    reverse(ret.begin(), ret.end());
    for (const auto &e : ret) cout << e << " ";
    cout << "\n";
    return 0;
}