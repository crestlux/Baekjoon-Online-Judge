#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, K;
    cin >> N >> K;
    vector<int> v(N);
    for (auto &e : v) cin >> e;
    int l = 0, r = 2e6 + 1, ret = 0;
    while (l <= r) {
        int mid = (l + r) >> 1, sum = 0, cnt = 0;
        for (int i = 0; i < N; ++i) {
            sum += v[i];
            if (sum >= mid) {
                ++cnt;
                sum = 0;
            }
        }
        if (cnt >= K) { ret = mid; l = mid + 1; }
        else r = mid - 1;
    }
    cout << ret << "\n";
    return 0;
}