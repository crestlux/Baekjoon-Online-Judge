#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
void buildmin(vector<int> &arr, vector<int> &segtree, int vtx, int tl, int tr) {
    if (tl == tr)  segtree[vtx] = arr[tl];
    else {
        int tm = (tl + tr) / 2;
        buildmin(arr, segtree, vtx * 2, tl, tm);
        buildmin(arr, segtree, vtx * 2 + 1, tm + 1, tr);
        segtree[vtx] = min(segtree[vtx * 2], segtree[vtx * 2 + 1]);
    }
}
void buildmax(vector<int> &arr, vector<int> &segtree, int vtx, int tl, int tr) {
    if (tl == tr)  segtree[vtx] = arr[tl];
    else {
        int tm = (tl + tr) / 2;
        buildmax(arr, segtree, vtx * 2, tl, tm);
        buildmax(arr, segtree, vtx * 2 + 1, tm + 1, tr);
        segtree[vtx] = max(segtree[vtx * 2], segtree[vtx * 2 + 1]);
    }
}
int minquery(vector<int> &segtree, int vtx, int tl, int tr, int l, int r) {
    if (l > r) return INT_MAX;
    if (l == tl && r == tr) return segtree[vtx];
    int tm = (tl + tr) / 2;
    return min(minquery(segtree, vtx * 2, tl, tm, l, min(r, tm)),
        minquery(segtree, vtx * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}
int maxquery(vector<int> &segtree, int vtx, int tl, int tr, int l, int r) {
    if (l > r) return INT_MIN;
    if (l == tl && r == tr) return segtree[vtx];
    int tm = (tl + tr) / 2;
    return max(maxquery(segtree, vtx * 2, tl, tm, l, min(r, tm)),
        maxquery(segtree, vtx * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M; vector<int> v, minseg, maxseg;
    cin >> N >> M;
    v.resize(N), minseg.resize(N << 2), maxseg.resize(N << 2);
    for (auto &e : v) {
        cin >> e;
    }
    buildmin(v, minseg, 1, 0, N - 1);
    buildmax(v, maxseg, 1, 0, N - 1);
    while (M--) {
        int l, r;
        cin >> l >> r;
        cout << minquery(minseg, 1, 0, N - 1, l - 1, r - 1) << " "
            << maxquery(maxseg, 1, 0, N - 1, l - 1, r - 1) << "\n";
    }
    return 0;
}