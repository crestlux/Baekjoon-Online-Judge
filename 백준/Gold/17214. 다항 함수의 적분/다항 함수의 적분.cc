#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    string s1, temp, ans; vector<int> v;
    cin >> s1;
    for (auto it = s1.begin(); it < s1.end(); it++) {
        if (*it == 'x') {
            v.push_back(stoi(temp));
            if (it + 1 != s1.end()) v.push_back(stoi(s1.substr(it + 1 - s1.begin(), s1.size())));
            else v.push_back(0);
        }
        temp += *it;
    }
    if (v.size() == 2) {
        if (v[1] >= 0) ans = to_string(v[0] / 2) + "xx+" + to_string(v[1]) + "x+W";
        else ans = to_string(v[0] / 2) + "xx" + to_string(v[1]) + "x+W";
    }
    else {
        if (stoi(temp) != 0) ans = temp + "x+W";
        else ans = "W";
    }
    ans = regex_replace(ans, regex("^1x"), "x");
    ans = regex_replace(ans, regex("\\+1x"), "+x");
    ans = regex_replace(ans, regex("\\-1x|^\\-1x"), "-x");
    ans = regex_replace(ans, regex("[+-]0x"), "");
    cout << ans << "\n";
    return 0;
}