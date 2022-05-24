#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    while (1) {
        char c; string s1;
        cin >> c;
        if (c == '#') break;
        cin.ignore();
        getline(cin, s1);
        auto ret = count_if(s1.begin(), s1.end(), [&](char s) {return (s == toupper(c) || s == tolower(c)); });
        cout << c << " " << ret << "\n";
    }
    return 0;
}