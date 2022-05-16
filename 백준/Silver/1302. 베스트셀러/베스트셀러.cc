#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
using psi = pair<string, int>;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; string s1; unordered_map<string, int> m;
    psi maxval;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> s1;
        m[s1]++;
    }
    maxval = *m.begin();
    for (const auto &e : m) {
        if (e.second > maxval.second) maxval = e;
        else if (e.second == maxval.second && e.first < maxval.first) maxval = e;
    }
    cout << maxval.first << "\n";
    return 0;
}