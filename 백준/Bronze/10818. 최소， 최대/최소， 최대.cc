#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    constexpr int k = 1e6 + 1;
    int n, maxval = -k, minval = k;
    cin >> n;
    while (n--) {
        int num;
        cin >> num;
        maxval = max(maxval, num);
        minval = min(minval, num);
    }
    cout << minval << " " << maxval << "\n";
    return 0;
}