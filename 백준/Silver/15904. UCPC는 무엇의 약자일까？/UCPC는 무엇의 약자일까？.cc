#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    char a; bool chkLetter[4];
    memset(chkLetter, 0, sizeof(chkLetter));
    while (cin >> a) {
        if (a == 'U') {
            chkLetter[0] = true;
            continue;
        }
        if (chkLetter[0] && a == 'C') {
            chkLetter[1] = true;
        }
        if (chkLetter[1] && a == 'P') {
            chkLetter[2] = true;
        }
        if (chkLetter[2] && a == 'C') {
            chkLetter[3] = true;
            break;
        }
    }
    chkLetter[3] ? cout << "I love UCPC" : cout << "I hate UCPC";
    return 0;
}