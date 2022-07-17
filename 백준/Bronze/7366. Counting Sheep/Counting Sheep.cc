#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        int n, cnt = 0;
        cin >> n;
        while (n--) {
            string s;
            cin >> s;
            if (s == "sheep") cnt++;
        }
        cout << "Case " << i << ": This list contains " << cnt << " sheep.\n\n";
    }
    return 0;
}