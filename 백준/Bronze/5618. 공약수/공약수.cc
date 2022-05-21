#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, ret = 0;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        if (i == 0) ret = num;
        else ret = gcd(ret, num);
    }
    for (int i = 1; i <= ret; ++i) {
        if (ret % i == 0) cout << i << "\n";
    }
    return 0;
}