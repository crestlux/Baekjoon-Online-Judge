#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, S, minret = INT_MAX;
    cin >> N >> S;
    vector<int> v(N, 0), pfx(N + 1, 0);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    partial_sum(v.begin(), v.end(), pfx.begin() + 1);
    int l = 0, r = 1;
    while (r <= N) {
        int sum = pfx[r] - pfx[l];
        if (sum >= S) {
            ++l;
            minret = min(r - l + 1, minret);
        }
        else { ++r; }
    }
    if (minret == INT_MAX) minret = 0;
    cout << minret << "\n";
    return 0;
}