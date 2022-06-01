#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, K, ret = INT_MAX; vector<int> v;
    cin >> N >> K;
    v.reserve(N);
    for (int i = 0; i < N; ++i) {
        int input;
        cin >> input;
        if (input == 1) v.push_back(i);
    }
    int vsz = v.size();
    int l = 0, r = K - 1;
    for (; r < vsz; ++l && ++r) {
        ret = min(ret, v[r] - v[l] + 1);
    }
    if(ret == INT_MAX) ret = -1;
    cout << ret << "\n";
    return 0;
}