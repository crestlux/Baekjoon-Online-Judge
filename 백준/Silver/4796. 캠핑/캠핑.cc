#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    while (1) {
        static int T = 1;
        int L, P, V;
        cin >> L >> P >> V;
        if (!P and !L and !V) break;
        cout << "Case " << T++ << ": " << min(V % P, L) + (V / P) * L << "\n";
    }
    return 0;
}