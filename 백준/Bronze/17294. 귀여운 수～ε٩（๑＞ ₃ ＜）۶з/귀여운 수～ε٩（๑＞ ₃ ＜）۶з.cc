#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    ull k; bool is_cute = true;
    cin >> k;
    while (is_cute) {
        if (k >= 1 && k <= 99) break;
        int p = (k % 10), q = (k / 10) % 10, r = (k / 100) % 10;
        if (p + r != (q << 1)) is_cute = false;
        k /= 10;
    }
    if (is_cute) cout << "◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!\n";
    else cout << "흥칫뿡!! <(￣ ﹌ ￣)>\n";
    return 0;
}