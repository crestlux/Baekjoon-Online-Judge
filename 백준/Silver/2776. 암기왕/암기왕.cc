#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        int N, M, num; unordered_map<int, bool> m;
        cin >> N;
        while (N--) {
            cin >> num;
            m[num] = true;
        }
        cin >> M;
        while (M--) {
            cin >> num;
            if (m.find(num) != m.end()) cout << "1\n";
            else cout << "0\n";
        }
    }
    return 0;
}