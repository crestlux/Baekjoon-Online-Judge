#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MAX = 1e9 + 1; queue<pair<ll, ll>> q;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    ll A, B, ret = -1;
    cin >> A >> B;
    auto bfs = [&](ll x) {
        q.push({ x, 1 });
        while (!q.empty()) {
            auto cur = q.front().first, cnt = q.front().second;
            q.pop();
            if (cur == B) {
                ret = cnt;
                return;
            }
            auto chk = [&](ll y) {
                if (y > 0 and y <= B) {
                    q.push({ y, cnt + 1 });
                }
            };
            chk(cur << 1);
            chk(cur * 10 + 1);
        }
    };
    bfs(A);
    cout << ret << "\n";
    return 0;
}