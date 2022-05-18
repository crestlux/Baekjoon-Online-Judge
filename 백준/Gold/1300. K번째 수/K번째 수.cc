#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, k, ret = 0;
    cin >> N >> k;
    int l = 1, r = k, mid;
    while (l <= r) {
        mid = (l + r) >> 1;
        int cnt = 0;
        for (int i = 1; i <= N; ++i) cnt += min(N, mid / i);
        if (k <= cnt) { ret = mid; r = mid - 1; }
        else l = mid + 1;
    }
    cout << ret << "\n";
    return 0;
}