#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N;
    cin >> N;
    vector<pair<int, int>> v(N);
    vector<int> inc(N, 0);
    for (auto &e : v) {
        int p, q;
        cin >> p >> q;
        e = { p,q };
    }
    sort(v.begin(), v.end());
    inc[0] = 1;
    constexpr int MIN = -987654321;
    for (int i = 1; i < N; ++i) {
        int maxlen = MIN;
        for (int j = 0; j < i; ++j) {
            if (v[i].second > v[j].second) maxlen = max(maxlen, inc[j] + 1);
        }
        inc[i] = (maxlen == MIN) ? 1 : maxlen;
    }
    cout << N - *max_element(inc.begin(), inc.end()) << "\n";
    return 0;
}