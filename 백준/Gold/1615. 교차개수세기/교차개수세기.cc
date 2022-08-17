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
    ll N = 0, M = 0, ret = 0;
    cin >> N >> M;
    vector<pair<ll, ll>> v(M);
    vector<ll> segtree((N + 1) << 2);
    vector<ll> cnt(N);
    for (auto &e : v) cin >> e.first >> e.second;
    ranges::sort(v);
    for (const auto &e : v) {
        ret += sum(segtree, 1, 0, N - 1, e.second, N - 1);
        cnt[e.second - 1]++;
        update(segtree, 1, 0, N - 1, e.second - 1, cnt[e.second - 1]);
    }
    cout << ret << "\n";
    return 0;
}