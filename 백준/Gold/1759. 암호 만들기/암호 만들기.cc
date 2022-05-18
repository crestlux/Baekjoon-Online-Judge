#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int L, C; string s;
    cin >> L >> C;
    vector<char> v(C); vector<string> ret;
    for (int i = 0; i < C; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for (int i = 1; i < (1LL << C); i++) {
        if (__builtin_popcount(i) != L) continue;
        int cons = 0, vow = 0;
        s = "";
        for (int j = 0; j < C; j++) {
            if (i & (1LL << j)) s += v[j];
        }
        for (auto it = s.begin(); it < s.end(); it++) {
            if (*it == 'a' || *it == 'e' || *it == 'i' || *it == 'o' || *it == 'u') vow++;
            else cons++;
        }
        if (cons >= 2 && vow >= 1) ret.push_back(s);
        else continue;
    }
    sort(ret.begin(), ret.end());
    for (const auto &e : ret) {
        cout << e << "\n";
    }
    return 0;
}