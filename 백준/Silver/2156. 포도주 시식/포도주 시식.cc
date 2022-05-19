#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int dp[10001][2];
//dp[i][0] = 0~i 중 i를 선택하고 i-1를 선택하지 않은 최대 포도주 양; [1] = i-1를 선택;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n; vector<int> v;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    dp[0][0] = dp[0][1] = v[0];
    dp[1][0] = v[1], dp[1][1] = v[0] + v[1];
    int maxt = dp[0][1], maxf = dp[0][0];
    for (int i = 2; i < n; ++i) {
        dp[i][0] = max(maxt, maxf) + v[i];
        dp[i][1] = dp[i - 1][0] + v[i];
        maxf = max(maxf, dp[i - 1][0]), maxt = max(maxt, dp[i - 1][1]);
    }
    cout << max({ maxt, maxf, dp[n - 1][0], dp[n - 1][1] }) << "\n";
    return 0;
}