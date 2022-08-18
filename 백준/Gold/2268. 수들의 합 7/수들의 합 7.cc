#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll sum(vector<ll> &segtree, ll vtx, ll tl, ll tr, ll l, ll r) {
    if (l > r) return 0;
    if (l == tl && r == tr) return segtree[vtx];
    ll tm = (tl + tr) / 2;
    return sum(segtree, vtx * 2, tl, tm, l, min(r, tm))
        + sum(segtree, vtx * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}
void update(vector<ll> &segtree, ll vtx, ll tl, ll tr, ll pos, ll new_val) {
    if (tl == tr) segtree[vtx] = new_val;
    else {
        ll tm = (tl + tr) / 2;
        if (pos <= tm) update(segtree, vtx * 2, tl, tm, pos, new_val);
        else update(segtree, vtx * 2 + 1, tm + 1, tr, pos, new_val);
        segtree[vtx] = segtree[vtx * 2] + segtree[vtx * 2 + 1];
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    ll N, M;
    cin >> N >> M;
    vector<ll> arr(N), segtree(N << 2);
    for (int i = 0; i < M; ++i) {
        ll p, q, r;
        cin >> p >> q >> r;
        if (p == 0) {
            if (q > r) swap(q, r);
            cout << sum(segtree, 1, 0, N - 1, q - 1, r - 1) << "\n";
        }
        else if (p == 1) {
            arr[q - 1] = r;
            update(segtree, 1, 0, N - 1, q - 1, r);
        }
    }
    return 0;
}