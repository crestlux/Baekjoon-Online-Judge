#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
vector<int> kmp(const string &t, const string &p) {
    vector<int> ret;
    auto buildPi = [&](const string &p) {
        int m = p.size(), j = 0;
        vector<int> pi(m, 0);
        for (int i = 1; i < m; i++) {
            while (j > 0 && p[i] != p[j]) j = pi[j - 1];
            if (p[i] == p[j]) pi[i] = ++j;
        }
        return pi;
    };
    auto pi = buildPi(p);
    int n = t.size(), m = p.size(), j = 0;
    for (int i = 0; i < n; i++) {
        while (j > 0 && t[i] != p[j]) j = pi[j - 1];
        if (t[i] == p[j]) {
            if (j == m - 1) {
                ret.push_back(i - m + 1);
                j = pi[j];
            }
            else j++;
        }
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    string src, s = "", target;
    cin >> src >> target;
    for (const auto &e : src) {
        if (e >= '0' and e <= '9') continue;
        else s += e;
    }
    auto matched = kmp(s, target);
    cout << !matched.empty() << "\n";
    return 0;
}