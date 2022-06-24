#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> v(N);
        for (auto &e : v) cin >> e;
        cout << accumulate(v.begin(), v.end(), 0) << "\n";
    }
    return 0;
}