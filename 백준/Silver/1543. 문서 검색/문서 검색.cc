#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    string src, dest;
    getline(cin, src);
    getline(cin, dest);
    int slen = src.length(), dlen = dest.length(), ret = 0;
    for (int i = 0; i <= slen - dlen;) {
        for (int j = 0; j < dlen; ++j) {
            if (src[i + j] != dest[j]) {
                ++i;
                break;
            }
            else {
                if (j == dlen - 1) {
                    i += dlen;
                    ++ret;
                }
            }
        }
    }
    cout << ret << "\n";
    return 0;
}