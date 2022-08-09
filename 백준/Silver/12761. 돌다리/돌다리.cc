#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    constexpr int r = 100001;
    int A, B, N, M, ret = 0; bitset<r> visited; queue<pair<int, int>> q;
    cin >> A >> B >> N >> M;
    auto bfs = [&](int x) {
        visited[x] = true;
        q.push({ x, 0 });
        while (!q.empty()) {
            int cur = q.front().first, cnt = q.front().second;
            if (cur == M) {
                ret = cnt;
                return;
            }
            q.pop();
            auto chk = [&](int y) {
                if (y >= 0 and y < r and !visited[y]) {
                    visited[y] = true;
                    q.push({ y, cnt + 1 });
                }
            };
            chk(cur * A);
            chk(cur * B);
            chk(cur + 1);
            chk(cur + A);
            chk(cur + B);
            chk(cur - A);
            chk(cur - B);
            chk(cur - 1);
        }
    };
    bfs(N);
    cout << ret << "\n";
    return 0;
}