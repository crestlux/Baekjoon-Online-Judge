#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
vector<int> v[2001]; bool visited[2001], chkfriend = false;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int p, q;
        cin >> p >> q;
        v[p].push_back(q), v[q].push_back(p);
    }
    function<bool(int, int)> dfs = [&](int x, int depth) {
        static bool chk = false;
        if (depth == 4) return true;
        for (int i = 0; i < int(v[x].size()); ++i) {
            if (!visited[v[x][i]]) {
                visited[v[x][i]] = true;
                chk = dfs(v[x][i], depth + 1);
            }
            if (chk) break;
        }
        visited[x] = false;
        return chk ? true : false;
    };
    for (int i = 0; i < N; ++i) {
        memset(visited, false, sizeof(visited));
        if (!visited[i]) {
            visited[i] = true;
            chkfriend = dfs(i, 0);
        }
        if (chkfriend) break;
    }
    chkfriend ? cout << "1\n" : cout << "0\n";
    return 0;
}