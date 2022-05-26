#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cout << fixed; cout.precision(0);
    long long n, k;
    cin >> n >> k;
    cout << 1 / (n * beta(n - k + 1, k)) << "\n";
    return 0;
}