#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M, R, cnt = 1;
    cin >> N >> M >> R;
    vector<pair<int, int>> info;
    info.reserve(M << 1);
    vector<int> v[200001], ret(N + 1, 0); bitset<100001> visited;
    for (int i = 0; i < M; ++i) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        info.emplace_back(make_pair(tmp1, tmp2));
        info.emplace_back(make_pair(tmp2, tmp1));
    }
    ranges::sort(info, greater<pair<int, int>>());
    for (const auto &e : info) {
        v[e.first].push_back(e.second);
    }
    function<void(int)> dfs = [&](int x) {
        for (const auto &e : v[x]) {
            if (!visited[e]) {
                visited[e] = true;
                ret[e] = ++cnt;
                dfs(e);
            }
        }
    };
    ret[R] = 1;
    visited[R] = true;
    dfs(R);
    for (int i = 1; i <= N; ++i) cout << ret[i] << "\n";
    return 0;
}