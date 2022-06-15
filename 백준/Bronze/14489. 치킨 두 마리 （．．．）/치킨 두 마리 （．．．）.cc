#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int A, B, C;
    cin >> A >> B >> C;
    if (A + B >= (C << 1)) cout << A + B - (C << 1) << "\n";
    else cout << A + B << "\n";
    return 0;
}