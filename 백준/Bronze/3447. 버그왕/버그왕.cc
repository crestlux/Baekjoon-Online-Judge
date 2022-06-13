#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    string s1; regex r(R"(BUG)", regex::optimize);
    while (getline(cin, s1)) {
        while (regex_search(s1, r)) s1 = regex_replace(s1, r, "");
        cout << s1 << "\n";
    }
    return 0;
}