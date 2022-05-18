#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, K, val = -987654321;
    cin >> N >> K;
    vector<int> v(N), pfx(N + 1, 0);
    for (int i = 0; i < N; i++)  cin >> v[i];
    partial_sum(v.begin(), v.end(), pfx.begin() + 1);
    for (int i = K; i <= N; i++) val = max(val, pfx[i] - pfx[i - K]);
    cout << val << "\n";
    return 0;
}