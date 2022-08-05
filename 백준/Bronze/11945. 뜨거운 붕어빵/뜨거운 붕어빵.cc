#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        ranges::reverse(s);
        cout << s << "\n";
    }
    return 0;
}