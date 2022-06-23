#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int a, b;
    cin >> a >> b;
    cout << (a * (100 - b) < 10000) << "\n";
    return 0;
}