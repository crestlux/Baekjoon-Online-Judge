#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; map<string, int> m;
    cin >> N;
    while (N--) {
        string s1;
        cin >> s1;
        s1.erase(s1.begin(), find(s1.begin(), s1.end(), '.') + 1);
        m[s1]++;
    }
    for (const auto &i : m) cout << i.first << " " << i.second << "\n";
    return 0;
}