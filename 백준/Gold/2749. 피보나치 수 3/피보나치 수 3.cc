#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll p = 15e5, mod = 1e6;
int v[p];
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    ll n;
    cin >> n;
    v[0] = 0, v[1] = 1;
    for (int i = 2; i < p; i++) v[i] = (v[i - 1] + v[i - 2]) % mod;
    cout << v[n % p] << "\n";
    return 0;
}