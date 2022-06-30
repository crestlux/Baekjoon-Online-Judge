#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    ull T;
    cin >> T;
    while (T--) {
        ull A, B;
        cin >> A >> B;
        auto f = [](ull n) -> ull {
            ull mod = n % 4ULL;
            if (!mod) return n;
            else if (mod == 1ULL) return 1ULL;
            else if (mod == 2ULL) return n + 1ULL;
            else return 0ULL;
        };
        cout << (f(A - 1) ^ f(B)) << "\n";
    }
    return 0;
}