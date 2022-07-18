#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    string A, B; ll ret = 0;
    cin >> A >> B;
    for (auto &e1 : A) {
        for (auto &e2 : B) {
            int n1 = e1 - '0', n2 = e2 - '0';
            ret += n1 * n2;
        }
    }
    cout << ret << "\n";
    return 0;
}