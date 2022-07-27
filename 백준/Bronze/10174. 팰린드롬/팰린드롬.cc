#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N;
    cin >> N;
    cin.ignore();
    while (N--) {
        string s, rs;
        getline(cin, s);
        for (auto &e : s) e = tolower(e);
        rs = s;
        ranges::reverse(rs);
        (s == rs) ? cout << "Yes\n" : cout << "No\n";
    }
    return 0;
}