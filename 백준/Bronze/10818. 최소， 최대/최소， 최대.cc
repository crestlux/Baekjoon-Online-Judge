#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &e : v) cin >> e;
    cout << *min_element(v.begin(), v.end()) << " " << *max_element(v.begin(), v.end()) << "\n";
    return 0;
}