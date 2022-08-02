#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> v[100001]; bitset<100001> visited;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n, ret = 0, pnt = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int p, q, dist;
        cin >> p;
        while (1) {
            cin >> q;
            if (q == -1) break;
            cin >> dist;
            v[p].emplace_back(make_pair(q, dist));
            v[q].emplace_back(make_pair(p, dist));
        }
    }
    function<void(int, int)> dfs = [&](int x, int len = 0) {
        visited[x] = true;
        if (ret < len) {
            ret = len;
            pnt = x;
        }
        for (const auto &e : v[x]) {
            if (!visited[e.first]) {
                dfs(e.first, len + e.second);
            }
        }
    };
    dfs(1, 0);
    visited.reset();
    ret = 0;
    dfs(pnt, 0);
    cout << ret << "\n";
    return 0;
}