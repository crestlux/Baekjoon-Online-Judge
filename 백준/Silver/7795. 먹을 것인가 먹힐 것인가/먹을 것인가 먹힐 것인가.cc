#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        int N, M, ret = 0; vector<int> v1, v2;
        cin >> N >> M;
        v1.resize(N), v2.resize(M);
        for (int i = 0; i < N; ++i)  cin >> v1[i];
        for (int i = 0; i < M; ++i)  cin >> v2[i];
        sort(v1.begin(), v1.end()); sort(v2.begin(), v2.end());
        for (int i = 0; i < N; ++i) ret += distance(v2.begin(), lower_bound(v2.begin(), v2.end(), v1[i]));
        cout << ret << "\n";
    }
    return 0;
}