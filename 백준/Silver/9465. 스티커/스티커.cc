#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int dp[100001][2], graph[100001][2];
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 0; i < 2; ++i) {
            for (int j = 1; j <= n; ++j) {
                cin >> graph[j][i];
            }
        }
        dp[1][0] = graph[1][0], dp[1][1] = graph[1][1];
        for (int i = 2; i <= n; ++i) {
            dp[i][0] = max(dp[i - 1][1], dp[i - 2][1]) + graph[i][0];
            dp[i][1] = max(dp[i - 1][0], dp[i - 2][0]) + graph[i][1];
        }
        cout << max(dp[n][0], dp[n][1]) << "\n";
    }
    return 0;
}