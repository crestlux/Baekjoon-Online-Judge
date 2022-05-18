#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int A, B;
    cin >> A >> B;
    cout << fixed; cout.precision(10);
    cout << 1.0 / (1 + pow(10, ((B - A) / 400.0))) << "\n";
    return 0;
}