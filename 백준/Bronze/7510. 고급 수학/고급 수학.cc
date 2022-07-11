#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        vector<int> v(3);
        for (auto &e : v) cin >> e;
        ranges::sort(v);
        if (v[0] * v[0] + v[1] * v[1] == v[2] * v[2]) {
            cout << "Scenario #" << i + 1 << ":\nyes\n\n";
        }
        else {
            cout << "Scenario #" << i + 1 << ":\nno\n\n";
        }
    }
    return 0;
}