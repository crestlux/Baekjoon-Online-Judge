#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    regex r(R"([a-zA-Z0-9]{6,9})");
    int N; string s1;
    cin >> N;
    while (N--) {
        cin >> s1;
        regex_match(s1, r) ? cout << "yes\n" : cout << "no\n";
    }
    return 0;
}