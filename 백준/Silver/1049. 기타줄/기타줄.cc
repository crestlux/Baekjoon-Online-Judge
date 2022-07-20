#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M, mp = INT_MAX, mq = INT_MAX;
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int p, q;
        cin >> p >> q;
        if (p < mp) mp = p;
        if (q < mq) mq = q;
    }
    int pack = N / 6;
    cout << min({ mp * (int)ceil(N / 6.0), mp * pack + mq * (N - pack * 6), mq * N }) << "\n";
    return 0;
}