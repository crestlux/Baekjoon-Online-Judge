#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    constexpr int MAX = 1e6 + 1;
    bitset<MAX> visited; queue<pair<int, int>> q;
    int A, K, ret = 0;
    cin >> A >> K;
    auto bfs = [&](int x) {
        visited[x] = true;
        q.push({ x,0 });
        while (!q.empty()) {
            int cur = q.front().first, cnt = q.front().second;
            q.pop();
            if (cur == K) {
                ret = cnt;
                return;
            }
            auto chk = [&](int y) {
                if (y > 0 && y <= K && !visited[y]) {
                    visited[y] = true;
                    q.push({ y, cnt + 1 });
                }
            };
            chk(cur + 1);
            chk(cur << 1);
        }
    };
    bfs(A);
    cout << ret << "\n";
    return 0;
}