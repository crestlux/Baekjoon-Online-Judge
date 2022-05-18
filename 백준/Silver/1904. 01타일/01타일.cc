#include <bits/stdc++.h>
using namespace std;
int dp[int(1e6 + 1)];
int main() {
    constexpr int mod = 15746;
    int N;
    dp[1] = 1, dp[2] = 2;
    for (int i = 3; i <= 1e6; i++) {
        dp[i] = (dp[i - 1] % mod + dp[i - 2] % mod) % mod;
    }
    cin >> N;
    cout << dp[N] << "\n";
    return 0;
}