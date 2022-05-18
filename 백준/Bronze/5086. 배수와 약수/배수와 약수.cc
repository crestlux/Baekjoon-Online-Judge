#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int p, q;
    while (1) {
        cin >> p >> q;
        if (p == 0 && q == 0) break;
        if (p % q == 0) cout << "multiple\n";
        else if (q % p == 0) cout << "factor\n";
        else cout << "neither\n";
    }
    return 0;
}