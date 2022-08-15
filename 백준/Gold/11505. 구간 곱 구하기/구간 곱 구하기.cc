#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll mod = 1000000007;
void build(vector<ll> &arr, vector<ll> &segtree, ll vtx, ll tl, ll tr) {
    if (tl == tr)  segtree[vtx] = arr[tl];
    else {
        ll tm = (tl + tr) / 2;
        build(arr, segtree, vtx * 2, tl, tm);
        build(arr, segtree, vtx * 2 + 1, tm + 1, tr);
        segtree[vtx] = ((segtree[vtx * 2] % mod) * (segtree[vtx * 2 + 1] % mod)) % mod;
    }
}
ll mul(vector<ll> &segtree, ll vtx, ll tl, ll tr, ll l, ll r) {
    if (l > r) return 1;
    if (l == tl && r == tr) return segtree[vtx];
    ll tm = (tl + tr) / 2;
    return ((mul(segtree, vtx * 2, tl, tm, l, min(r, tm)) % mod)
        * (mul(segtree, vtx * 2 + 1, tm + 1, tr, max(l, tm + 1), r) % mod)) % mod;
}
void update(vector<ll> &segtree, ll vtx, ll tl, ll tr, ll pos, ll new_val) {
    if (tl == tr) segtree[vtx] = new_val;
    else {
        ll tm = (tl + tr) / 2;
        if (pos <= tm) update(segtree, vtx * 2, tl, tm, pos, new_val);
        else update(segtree, vtx * 2 + 1, tm + 1, tr, pos, new_val);
        segtree[vtx] = ((segtree[vtx * 2] % mod) * (segtree[vtx * 2 + 1] % mod)) % mod;
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    ll N, M, K;
    cin >> N >> M >> K;
    vector<ll> v(N), segtree(N << 2);
    for (auto &e : v) cin >> e;
    build(v, segtree, 1, 0, N - 1);
    for (int i = 0; i < M + K; ++i) {
        ll p, q, r;
        cin >> p >> q >> r;
        if (p == 1) {
            v[q - 1] = r;
            update(segtree, 1, 0, N - 1, q - 1, r);
        }
        else if (p == 2) {
            cout << mul(segtree, 1, 0, N - 1, q - 1, r - 1) << "\n";
        }
    }
    return 0;
}