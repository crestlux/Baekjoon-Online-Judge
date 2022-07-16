#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        int s, n, sum = 0;
        cin >> s;
        cin >> n;
        while (n--) {
            int p, q;
            cin >> p >> q;
            sum += p * q;
        }
        cout << sum + s << "\n";
    }
    return 0;
}