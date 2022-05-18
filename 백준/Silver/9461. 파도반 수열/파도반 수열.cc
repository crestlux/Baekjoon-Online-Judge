#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T, N; long long dp[103];
    dp[1] = dp[2] = dp[3] = 1;
    dp[4] = dp[5] = 2;
    for (int i = 6; i < 101; i++) {
        dp[i] = dp[i - 1] + dp[i - 5];
    }
    cin >> T;
    while (T--) {
        cin >> N;
        cout << dp[N] << "\n";
    }
    return 0;
}