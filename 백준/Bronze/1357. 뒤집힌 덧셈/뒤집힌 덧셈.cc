#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    string s1, s2, ret;
    cin >> s1 >> s2;
    ranges::reverse(s1), ranges::reverse(s2);
    ret = to_string(stoi(s1) + stoi(s2));
    ranges::reverse(ret);
    cout << stoi(ret) << "\n";
    return 0;
}