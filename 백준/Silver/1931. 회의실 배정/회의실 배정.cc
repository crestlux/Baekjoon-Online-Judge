#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, ret = 1;
    cin >> N;
    vector<pii> v(N);
    for (int i = 0; i < N; ++i) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end(), [&](const pii &a, const pii &b) {
        if (a.second == b.second) {
            return a.first < b.first;
        }
        return a.second < b.second;
    });
    int selhi = v[0].second;
    for (int i = 1; i < N; ++i) {
        if (v[i].first >= selhi) {
            selhi = v[i].second;
            ++ret;
        }
    }
    cout << ret << "\n";
    return 0;
}