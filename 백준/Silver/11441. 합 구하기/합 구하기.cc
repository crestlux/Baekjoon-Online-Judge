#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M;
    cin >> N;
    vector<int> v(N), pfx(N + 1, 0);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    partial_sum(v.begin(), v.end(), pfx.begin() + 1);
    cin >> M;
    while (M--) {
        pair<int, int> q;
        cin >> q.first >> q.second;
        cout << pfx[q.second] - pfx[q.first - 1] << "\n";
    }
    return 0;
}