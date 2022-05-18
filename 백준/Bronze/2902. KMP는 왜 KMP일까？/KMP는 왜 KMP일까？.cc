#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    string s1, ret;
    cin >> s1;
    ret += *s1.begin();
    for (auto it = s1.begin() + 1; it < s1.end(); it++) {
        if (*it == '-') ret += *(++it);
    }
    cout << ret << "\n";
    return 0;
}