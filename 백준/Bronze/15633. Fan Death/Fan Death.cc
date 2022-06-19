#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, ret = 0;
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        if (!(N % i)) ret += i;
    }
    cout << ret * 5 - 24 << "\n";
    return 0;
}