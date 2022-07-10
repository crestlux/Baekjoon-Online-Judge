#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, ret = 0;
    cin >> N;
    for (int a = 1; a <= 500; ++a) {
        for (int b = 1; b <= a; ++b) {
            if (a * a == b * b + N) ++ret;
        }
    }
    cout << ret << "\n";
    return 0;
}