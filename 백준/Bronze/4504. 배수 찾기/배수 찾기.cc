#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    while (1) {
        int num;
        cin >> num;
        if (!num) break;
        if (num % n) cout << num << " is NOT a multiple of " << n << ".\n";
        else cout << num << " is a multiple of " << n << ".\n";
    }
    return 0;
}