#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int p, q, r;
    while (1) {
        cin >> p >> q >> r;
        if (!p && !q && !r) break;
        if ((p + r == (q << 1)) && (r - q)) cout << "AP " << (r << 1) - q << "\n";
        else cout << "GP " << r * r / q << "\n";
    }
    return 0;
}