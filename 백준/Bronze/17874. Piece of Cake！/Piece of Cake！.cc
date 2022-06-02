#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n, h, v;
    cin >> n >> h >> v;
    cout << max(h, n - h) * max(v, n - v) * 4 << "\n";
    return 0;
}