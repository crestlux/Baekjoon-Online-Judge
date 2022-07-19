#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int num, ret = 0;
    while (cin >> num) {
        if (num > 0) ret++;
    }
    cout << ret << "\n";
    return 0;
}