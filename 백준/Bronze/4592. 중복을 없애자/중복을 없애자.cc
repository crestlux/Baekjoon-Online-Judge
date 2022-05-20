#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    while (1) {
        int N, num = 0, prevnum = 0;
        cin >> N;
        if (N == 0) break;
        for (int i = 0; i < N; ++i) {
            cin >> num;
            if (num != prevnum) cout << num << " ";
            prevnum = num;
        }
        cout << "$\n";
    }
    return 0;
}