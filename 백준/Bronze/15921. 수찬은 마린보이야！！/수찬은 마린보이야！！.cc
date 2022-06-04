#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, sum = 0;
    cin >> N;
    vector<int> v(N);
    for (auto &e : v) cin >> e;
    sum = accumulate(v.begin(), v.end(), 0);
    if (sum) cout << "1.00\n";
    else cout << "divide by zero\n";
    return 0;
}