#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, lim;
    cin >> N;
    vector<ll> v(N);
    for (auto &e : v) cin >> e;
    cin >> lim;
    if (accumulate(v.begin(), v.end(), 0) <= lim) cout << *max_element(v.begin(), v.end()) << "\n";
    else {
        ll l = 0, r = lim, ret = 0;
        while (l <= r) {
            ll mid = (l + r) >> 1, cur = 0;
            for (const auto &e : v) cur += min(e, mid);
            //cout << "(l, r): (" << l << ", " << r << ") mid: " << mid << " cur: " << cur << "\n";
            if (cur > lim) r = mid - 1;
            else {
                ret = max(ret, mid);
                l = mid + 1;
            }
        }
        cout << ret << "\n";
    }
    return 0;
}