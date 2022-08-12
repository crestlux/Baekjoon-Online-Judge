#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int mod = 987654321;
ll dp[100001][11];
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    ll n, ret = 0;
    cin >> n;
    fill(&dp[1][1], &dp[1][1] + 9, 1);
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= 9; ++j) {
            dp[i][j] = (dp[i - 1][max(j - 2, 0)] + dp[i - 1][max(j - 1, 0)] + dp[i - 1][j] + dp[i - 1][min(j + 1, 10)] + dp[i - 1][min(j + 2, 10)]) % mod;
        }
    }
    for (int i = 1; i <= 9; ++i) {
        ret = (ret + dp[n][i]) % mod;
    }
    cout << ret << "\n";
    return 0;
}