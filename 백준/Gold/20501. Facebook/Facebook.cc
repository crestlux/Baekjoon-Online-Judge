#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, Q;
    cin >> N;
    vector<bitset<2000>> v(N);
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        v[i] = bitset<2000>(s);
    }
    cin >> Q;
    while (Q--) {
        int p, q;
        cin >> p >> q;
        cout << (v[p - 1] & v[q - 1]).count() << "\n";
    }
    return 0;
}