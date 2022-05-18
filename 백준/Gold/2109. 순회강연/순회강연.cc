#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, ret = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq; vector<pii> v;
    cin >> N;
    while (N--) {
        pair<int, int> p;
        cin >> p.first >> p.second;
        v.emplace_back(p);
    }
    sort(v.begin(), v.end(), [&](pii &a, pii &b) {
        if (a.second == b.second) return a.first < b.first;
        else return a.second < b.second;
    });
    for (const auto &e : v) {
        pq.push(e);
        if (e.second < pq.size()) pq.pop();
    }
    while (!pq.empty()) {
        ret += pq.top().first;
        pq.pop();
    }
    cout << ret << "\n";
    return 0;
}