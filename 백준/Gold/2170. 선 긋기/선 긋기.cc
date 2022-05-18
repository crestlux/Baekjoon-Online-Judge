#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
constexpr int INF = INT_MIN;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N;
    cin >> N;
    vector<pii> v(N);
    for (int i = 0; i < N; ++i) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());
    int ret = 0, l = INF, r = INF;
    for (int i = 0; i < N; ++i) {
        if (r >= v[i].first) r = max(v[i].second, r);
        else {
            ret += r - l;
            l = v[i].first, r = v[i].second;
        }
    }
    ret += r - l;
    cout << ret << "\n";
    return 0;
}