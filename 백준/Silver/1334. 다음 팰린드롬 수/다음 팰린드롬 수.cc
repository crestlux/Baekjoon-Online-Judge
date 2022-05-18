#include <bits/stdc++.h>
using namespace std;
bool operator> (string s1, string s2) {
    if (s1.length() < s2.length()) {
        reverse(s1.begin(), s1.end());
        while (s1.length() != s2.length()) s1 += '0';
        reverse(s1.begin(), s1.end());
    }
    else {
        reverse(s2.begin(), s2.end());
        while (s1.length() != s2.length()) s2 += '0';
        reverse(s2.begin(), s2.end());
    }
    size_t slen = s1.length();
    for (size_t i = 0; i < slen; i++) {
        if (s1[i] < s2[i]) return false;
        else if (s1[i] == s2[i]) continue;
        else return true;
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    string s1, t1;
    cin >> s1;
    t1 = s1;
    int tlen = static_cast<int>(t1.length());
    for (int i = 0; i < tlen / 2; i++) {
        if (t1[i] != t1[tlen - i - 1]) t1[tlen - i - 1] = t1[i];
    }
    if (t1 > s1) cout << t1 << "\n";
    else {
        if (t1[(tlen + 1) / 2 - 1] == '9') {
            int carry = 1, idx = (tlen + 1) / 2 - 1;
            t1[idx--] = '0';
            while (carry != 0 && idx >= 0) {
                int update_carry = (t1[idx] - '0' + carry) / 10;
                t1[idx] = (t1[idx] - '0' + carry) % 10 + '0';
                carry = update_carry;
                idx--;
            }
            if (carry != 0) {
                t1.insert(t1.begin(), '1');
                carry = 0;
            }
        }
        else {
            t1[(tlen + 1) / 2 - 1]++;
        }
        tlen = static_cast<int>(t1.length());
        for (int i = 0; i < tlen / 2; i++) {
            if (t1[i] != t1[tlen - i - 1]) t1[tlen - i - 1] = t1[i];
        }
        cout << t1 << "\n";
    }
    return 0;
}