#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
bool dp[2002][2002];
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M;
    cin >> N;
    vector<int> v(N + 2, 0);
    for (int i = 1; i <= N; ++i) cin >> v[i];
    for (int i = 1; i <= N; ++i) {
        dp[i][0] = true;
        dp[i][1] = (v[i] == v[i + 1]);
    }
    for (int gap = 2; gap < N; ++gap) {
        for (int from = 1; from <= N - gap; ++from) {
            dp[from][gap] = (dp[from + 1][gap - 2] && v[from] == v[from + gap]);
        }
    }
    cin >> M;
    while (M--) {
        int p, q;
        cin >> p >> q;
        cout << dp[p][q - p] << "\n";
    }
    return 0;
}