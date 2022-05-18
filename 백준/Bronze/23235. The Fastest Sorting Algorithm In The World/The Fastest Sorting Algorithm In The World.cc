#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int tc = 1;
    while (1) {
        int N, tmp;
        cin >> N;
        if (N == 0) break;
        while (N--) cin >> tmp;
        cout << "Case " << tc++ << ": Sorting... done!\n";
    }
    return 0;
}