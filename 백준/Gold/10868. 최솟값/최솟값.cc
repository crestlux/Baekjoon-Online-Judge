#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
void build(vector<int> &arr, vector<int> &segtree, int vtx, int tl, int tr) {
    if (tl == tr)  segtree[vtx] = arr[tl];
    else {
        int tm = (tl + tr) / 2;
        build(arr, segtree, vtx * 2, tl, tm);
        build(arr, segtree, vtx * 2 + 1, tm + 1, tr);
        segtree[vtx] = min(segtree[vtx * 2], segtree[vtx * 2 + 1]);
    }
}
int query(vector<int> &segtree, int vtx, int tl, int tr, int l, int r) {
    if (l > r) return INT_MAX;
    if (l == tl && r == tr) return segtree[vtx];
    int tm = (tl + tr) / 2;
    return min(query(segtree, vtx * 2, tl, tm, l, min(r, tm)),
        query(segtree, vtx * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M; vector<int> v, segtree;
    cin >> N >> M;
    v.resize(N), segtree.resize(N << 2);
    for (auto &e : v) {
        cin >> e;
    }
    build(v, segtree, 1, 0, N - 1);
    while (M--) {
        int l, r;
        cin >> l >> r;
        cout << query(segtree, 1, 0, N - 1, l - 1, r - 1) << "\n";
    }
    return 0;
}