#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    vector<int> v(31, 0);
    for (int i = 0; i < 28; ++i) {
        int num;
        cin >> num;
        v[num]++;
    }
    for (int i = 1; i <= 30; ++i) {
        if (!v[i]) cout << i << "\n";
        else continue;
    }
    return 0;
}