#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, K, ret = 0; constexpr int MAX = 100001;
    bitset<MAX> visited; queue<pair<int, int>> q;
    cin >> N >> K;
    auto bfs = [&](int x) {
        visited[x] = true;
        q.push({ x, 0 });
        while (!q.empty()) {
            int loc = q.front().first, t = q.front().second;
            q.pop();
            if (loc == K) {
                ret = t;
                return;
            }
            auto chk = [&](int tar) {
                if (tar >= 0 && tar < MAX && !visited[tar]) {
                    visited[tar] = true;
                    q.push({ tar, t + 1 });
                }
            };
            chk(loc - 1);
            chk(loc + 1);
            chk(loc << 1);
        }
    };
    bfs(N);
    cout << ret << "\n";
    return 0;
}