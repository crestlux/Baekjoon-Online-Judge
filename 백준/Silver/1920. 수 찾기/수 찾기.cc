#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M;
    cin >> N;
    vector<int> v1(N);
    for (auto &e : v1) cin >> e;
    ranges::sort(v1);
    cin >> M;
    vector<int> v2(M);
    for (auto &e : v2) cin >> e;
    for (const auto &e : v2) {
        cout << ranges::binary_search(v1, e) << "\n";
    }
    return 0;
}