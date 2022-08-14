#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll sz = (4 * 1e6);
ll segtree[sz];
void build(vector<ll> &a, ll vtx_idx, ll tl, ll tr) {
    if (tl == tr)  segtree[vtx_idx] = a[tl];
    else {
        ll tm = (tl + tr) / 2;
        build(a, vtx_idx * 2, tl, tm);
        build(a, vtx_idx * 2 + 1, tm + 1, tr);
        segtree[vtx_idx] = segtree[vtx_idx * 2] + segtree[vtx_idx * 2 + 1];
    }
}
ll sum(ll vtx_idx, ll tl, ll tr, ll l, ll r) {
    if (l > r) return 0;
    if (l == tl && r == tr) return segtree[vtx_idx];
    ll tm = (tl + tr) / 2;
    return sum(vtx_idx * 2, tl, tm, l, min(r, tm)) + sum(vtx_idx * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}
void update(ll vtx_idx, ll tl, ll tr, ll pos, ll new_val) {
    if (tl == tr) segtree[vtx_idx] = new_val;
    else {
        ll tm = (tl + tr) / 2;
        if (pos <= tm) update(vtx_idx * 2, tl, tm, pos, new_val);
        else update(vtx_idx * 2 + 1, tm + 1, tr, pos, new_val);
        segtree[vtx_idx] = segtree[vtx_idx * 2] + segtree[vtx_idx * 2 + 1];
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    ll N, M, K; vector<ll> arr;
    cin >> N >> M >> K;
    arr.resize(N);
    for (auto &e : arr) {
        cin >> e;
    }
    build(arr, 1, 0, N - 1);
    for (int i = 0; i < M + K; ++i) {
        ll p, q, r;
        cin >> p >> q >> r;
        if (p == 1) {
            arr[q - 1] = r;
            update(1, 0, N - 1, q - 1, r);
        }
        else if (p == 2) {
            cout << sum(1, 0, N - 1, q - 1, r - 1) << "\n";
        }
    }
    return 0;
}