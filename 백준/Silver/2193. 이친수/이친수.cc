#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
unsigned long long dp[91][2];
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N;
    cin >> N;
    dp[1][1] = 1; dp[2][0] = 1; dp[3][0] = 1, dp[3][1] = 1;
    for (int i = 4; i <= 90; ++i) {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
        dp[i][1] = dp[i - 1][0];
    }
    cout << dp[N][0] + dp[N][1] << "\n";
    return 0;
}