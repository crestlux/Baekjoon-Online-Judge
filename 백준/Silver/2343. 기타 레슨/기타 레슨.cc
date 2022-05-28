#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    vector<int> v(N);
    for (auto &e : v) cin >> e;
    int l = 0, r = accumulate(v.begin(), v.end(), 0), ret = 0;
    while (l <= r) {
        int mid = (l + r) >> 1, cnt = 1, len = 0; bool b = true;
        for (int i = 0; i < N; ++i) {
            if (v[i] > mid) { b = false; break; }
            len += v[i];
            if (len > mid) {
                ++cnt;
                len = v[i];
            }
        }
        if (cnt > M || !b) l = mid + 1;
        else { ret = mid; r = mid - 1; }
    }
    cout << ret << "\n";
    return 0;
}