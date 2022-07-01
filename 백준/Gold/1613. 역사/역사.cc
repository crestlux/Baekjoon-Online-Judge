#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n, k, s;
    cin >> n >> k;
    vector<vector<int>> v(n + 1); vector<bool> visited(n + 1, false);
    while (k--) {
        int p, q;
        cin >> p >> q;
        v[p].push_back(q);
    }
    function<bool(const int, const int)> dfs = [&](const int &x, const int &tar) {
        if (x == tar) return true;
        for (const auto &e : v[x]) {
            if (!visited[e]) {
                visited[e] = true;
                if (dfs(e, tar)) return true;
            }
        }
        return false;
    };
    cin >> s;
    while (s--) {
        fill(visited.begin(), visited.end(), false);
        int p, q;
        cin >> p >> q;
        if (dfs(p, q)) cout << "-1\n";
        else if (dfs(q, p)) cout << "1\n";
        else cout << "0\n";
    }
    return 0;
}