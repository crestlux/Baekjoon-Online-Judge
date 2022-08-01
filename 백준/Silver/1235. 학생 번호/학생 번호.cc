#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, slen = 0, ret = 0;
    cin >> N;
    vector<string> v(N);
    for (auto &e : v) cin >> e;
    slen = v[0].length();
    for (int i = 1; i <= slen; ++i) {
        set<string> s;
        for (const auto &e : v) s.insert(e.substr(slen - i, i));
        if (s.size() == size_t(N)) { ret = i; break; }
    }
    cout << ret << "\n";
    return 0;
}