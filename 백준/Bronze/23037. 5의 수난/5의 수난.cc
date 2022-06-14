#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n, ret = 0;
    cin >> n;
    while (n) {
        ret += pow(n % 10, 5);
        n /= 10;
    }
    cout << ret << "\n";
    return 0;
}