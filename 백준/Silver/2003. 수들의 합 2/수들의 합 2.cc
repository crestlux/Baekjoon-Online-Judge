#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M, ret = 0;
    cin >> N >> M;
    vector<int> v(N, 0), pfx(N + 1, 0);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    partial_sum(v.begin(), v.end(), pfx.begin() + 1);
    int l = 0, r = 1;
    for (; r <= N; r++) {
        int sum = pfx[r] - pfx[l];
        if (sum >= M) {
            if (sum == M) ret++;
            ++l; r = l;
            continue;
        }
    }
    cout << ret << "\n";
    return 0;
}