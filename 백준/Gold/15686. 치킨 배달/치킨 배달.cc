#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
class house {
public:
    house(pii h) : house_coord(h), ch_dst(INT_MAX) {}
    pii house_coord;
    int ch_dst;
};
int dst(const pii &a, const pii &b) { return abs(a.first - b.first) + abs(a.second - b.second); }
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M, ret = INT_MAX; int graph[51][51] = { 0, };
    constexpr int MAX_CHICKEN = 13;
    vector<pii> ch; vector<house> h;
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> graph[i][j];
            if (graph[i][j] == 1) h.push_back(house({ i, j }));
            else if (graph[i][j] == 2) ch.push_back({ i, j });
        }
    }
    int hsz = h.size(), chsz = ch.size();
    for (int i = 1; i < (1LL << chsz); i++) {
        if (__builtin_popcount(i) != M) continue;
        int cur = 0;
        for (int k = 0; k < hsz; k++) { h[k].ch_dst = INT_MAX; }
        for (int j = 0; j < MAX_CHICKEN; j++) {
            if (i & (1LL << j)) {
                for (int k = 0; k < hsz; k++) {
                    h[k].ch_dst = min(h[k].ch_dst, dst(h[k].house_coord, ch[j]));
                }
            }
        }
        for (int k = 0; k < hsz; k++) cur += h[k].ch_dst;
        ret = min(cur, ret);
    }
    cout << ret << "\n";
    return 0;
}