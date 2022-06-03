#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int S, M, L;
    cin >> S >> M >> L;
    if (S + ((M + L) << 1) + L >= 10) cout << "happy\n";
    else cout << "sad\n";
    return 0;
}