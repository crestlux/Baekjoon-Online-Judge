#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; map<pair<int, int>, int> m;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int p, q, g;
        cin >> p >> q;
        g = gcd(p, q);
        m[{p / g, q / g}]++;
    }
    int maxval = -1;
    for (const auto &e : m)maxval = max(maxval, e.second);
    cout << maxval << "\n";
    return 0;
}