#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int alph[26];
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    string s; char ret = 0;
    cin >> s;
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    for (const auto &e : s) alph[e - 'A']++;
    for (int i = 0; const auto &e : alph) {
        static int maxval = -1;
        if (maxval < e) {
            maxval = e;
            ret = i + 'A';
        }
        else if (maxval == e) ret = '?';
        ++i;
    }
    cout << ret << "\n";
    return 0;
}