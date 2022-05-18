#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T, N;
    cin >> T;
    while (T--) {
        cin >> N;
        ll maxval = -1;
        ll ret = 0;
        vector<ll> v(N);
        for (int i = 0; i < N; ++i) {
            cin >> v[i];
        }
        for (int i = N - 1; i >= 0; --i) {
            if (v[i] < maxval) ret += (maxval - v[i]);
            else maxval = v[i];
        }
        cout << ret << "\n";
    }
    return 0;
}