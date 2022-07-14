#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    cout << min(A + D, B + C) << "\n";
    return 0;
}