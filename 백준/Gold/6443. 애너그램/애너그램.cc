#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        string s1, tmp = "";
        cin >> s1;
        sort(s1.begin(), s1.end());
        do {
            if (s1 == tmp) continue;
            else {
                cout << s1 << "\n";
                tmp = s1;
            }
        } while (next_permutation(s1.begin(), s1.end()));
    }
    return 0;
}