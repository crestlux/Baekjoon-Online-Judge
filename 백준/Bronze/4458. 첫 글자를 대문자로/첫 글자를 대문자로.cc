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
        string s;
        getline(cin, s);
        s[0] = toupper(s[0]);
        cout << s << "\n";
    }
    return 0;
}