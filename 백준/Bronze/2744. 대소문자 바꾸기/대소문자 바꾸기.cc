#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    string s1;
    cin >> s1;
    for (auto &i : s1) {
        i = (islower(i)) ? toupper(i) : tolower(i);
    }
    cout << s1 << "\n";
    return 0;
}