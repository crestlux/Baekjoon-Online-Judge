#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M, D;
    cin >> N >> M;
    vector<int> v(N);
    for (int i = 0; i < N; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < M; ++i) {
        cin >> D;
        auto it = lower_bound(v.begin(), v.end(), D);
        if (it != v.end() && (*it) == D) cout << abs(distance(v.begin(), it)) << "\n";
        else cout << "-1\n";
    }
    return 0;
}