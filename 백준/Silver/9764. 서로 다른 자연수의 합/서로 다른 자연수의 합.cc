#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    constexpr int mod = 100999; int T, dp[2001][2001] = { 0, };
    for (int i = 0; i < 2001; i++) {
        dp[0][i] = 1;
    }
    for (int i = 1; i < 2001; i++) {
        for (int j = 1; j < 2001; j++) {
            dp[i][j] = dp[i][j - 1];
            if (i >= j) dp[i][j] = (dp[i][j] % mod + dp[i - j][j - 1] % mod) % mod;
        }
    }
    cin >> T;
    while (T--) {
        int temp;
        cin >> temp;
        cout << dp[temp][temp] << "\n";
    }
    return 0;
}