#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    vector<vi> v1(N, vi(M)), v2(N, vi(M));
    for (auto &e1 : v1) for (auto &e2 : e1) cin >> e2;
    for (auto &e1 : v2) for (auto &e2 : e1) cin >> e2;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j)
            cout << v1[i][j] + v2[i][j] << " ";
        cout << "\n";
    }
    return 0;
}