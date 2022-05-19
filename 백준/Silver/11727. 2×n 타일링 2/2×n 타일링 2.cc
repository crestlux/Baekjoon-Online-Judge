#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int dp[1001];
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; constexpr int mod = 10007;
    cin >> N;
    dp[1] = 1, dp[2] = 3;
    for (int i = 3; i <= N; ++i) {
        dp[i] = ((dp[i - 2] << 1) % mod + dp[i - 1] % mod) % mod;
    }
    cout << dp[N] << "\n";
    return 0;
}