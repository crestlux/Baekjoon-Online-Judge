#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int v[201];
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, ret;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        v[num + 100]++;
    }
    cin >> ret;
    cout << v[ret + 100] << "\n";
    return 0;
}