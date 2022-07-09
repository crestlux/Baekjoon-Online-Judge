#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int v[9][9], mval = -1, mi = 0, mj = 0;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin >> v[i][j];
            if (v[i][j] > mval) {
                mval = v[i][j];
                mi = i, mj = j;
            }
        }
    }
    cout << mval << "\n" << mi + 1 << " " << mj + 1 << "\n";
    return 0;
}