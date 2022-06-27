#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        vector<int> v;
        for (int i = 0; i < 7; ++i) {
            int num;
            cin >> num;
            if (!(num & 1)) v.emplace_back(num);
        }
        cout << accumulate(v.begin(), v.end(), 0) << " " << *min_element(v.begin(), v.end()) << "\n";
    }
    return 0;
}