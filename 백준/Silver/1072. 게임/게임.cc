#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    long long X, Y, Z;
    cin >> X >> Y;
    Z = Y * 100 / X;
    if (X == Y || Z == 99) cout << "-1\n";
    else {
        long long l = 0, r = 2e9;
        while (l <= r) {
            long long mid = (l + r) >> 1, rate = (Y + mid) * 100 / (X + mid);
            if (Z != rate) r = mid - 1;
            else l = mid + 1;
        }
        cout << l << "\n";
    }
    return 0;
}