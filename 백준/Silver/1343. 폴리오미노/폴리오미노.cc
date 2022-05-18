#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    string s1;
    cin >> s1;
    int slen = s1.length();
    for (int i = 0; i < slen; i++) {
        if (i <= slen - 4 && s1.substr(i, 4) == "XXXX") {
            s1.replace(i, 4, "AAAA");
        }
        else if (i <= slen - 2 && s1.substr(i, 2) == "XX") {
            s1.replace(i, 2, "BB");
        }
        else if (i <= slen - 1 && s1.substr(i, 1) == "X") {
            s1 = "-1";
            break;
        }
    }
    cout << s1 << "\n";
    return 0;
}