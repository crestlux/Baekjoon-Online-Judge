#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
int N, M;
vector<vi> v;
vi indegree;
priority_queue <int, vi, greater<int>> pq;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M;
    v.resize(N + 1);
    indegree.resize(N + 1);
    while (M--) {
        int p, q;
        cin >> p >> q;
        indegree[q]++;
        v[p].push_back(q);
    }
    for (int i = 1; i <= N; ++i) {
        if (!indegree[i]) pq.push(i);
    }
    while (!pq.empty()) {
        int cur = pq.top();
        pq.pop();
        cout << cur << " ";
        for (const auto &e : v[cur]) {
            if (!(--indegree[e])) pq.push(e);
        }
    }
    return 0;
}