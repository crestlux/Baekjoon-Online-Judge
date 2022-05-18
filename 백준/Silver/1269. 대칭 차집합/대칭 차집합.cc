#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int A, B, num, ret = 0; map<int, int> m;
    cin >> A >> B;
    for (int i = 0; i < A; ++i) {
        cin >> num;
        m[num]++;
    }
    for (int i = 0; i < B; ++i) {
        cin >> num;
        m[num]++;
    }
    for (auto it = m.begin(); it != m.end(); ++it) {
        if (it->second == 1) ++ret;
    }
    cout << ret << "\n";
    return 0;
}