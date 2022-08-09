#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T; vector<string> num;
    cin >> T;
    while (T--) {
        string s, tmp = "";
        auto parse = [&]() {
            if (!tmp.empty()) {
                const regex pattern("^0+(?!$)", regex::optimize);
                tmp = regex_replace(tmp, pattern, "");
                num.emplace_back(tmp);
                tmp.clear();
            }
        };
        cin >> s;
        for (const auto &e : s) {
            if (e >= '0' and e <= '9') tmp += e;
            else parse();
        }
        parse();
    }
    sort(num.begin(), num.end(), [&](const string &s1, const string &s2) {
        if (s1.length() == s2.length()) return s1.compare(s2) < 0;
        else return s1.length() < s2.length();
    });
    for (const auto &e : num) {
        cout << e << "\n";
    }
    return 0;
}