#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    string s;
    cin >> s;
    if (s.length() == 7 and s.substr(0, 3) == "555" and stoi(s) >= 0 and stoi(s) <= 9999999) {
        cout << "YES";
    }
    else cout << "NO\n";
    return 0;
}