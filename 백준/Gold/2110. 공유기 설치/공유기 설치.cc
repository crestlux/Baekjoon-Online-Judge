#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, C;
    cin >> N >> C;
    vector<int> v(N);
    for (int i = 0; i < N; ++i) cin >> v[i];
    sort(v.begin(), v.end());
    int l = 1, r = v[N - 1] - v[0], ret = 0;
    while (l <= r) {
        int mid = (l + r) >> 1, cnt = 1, prev = v[0];
        for (int i = 1; i < N; ++i) {
            if (v[i] - prev >= mid) {
                ++cnt;
                prev = v[i];
            }
        }
        if (cnt >= C) {
            ret = max(ret, mid);
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << ret << "\n";
    return 0;
}