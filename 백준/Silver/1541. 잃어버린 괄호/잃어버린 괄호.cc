#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    string exp, num = "";
    int first_of_subidx = -1, opcnt = 0;
    vector<int> nv;
    cin >> exp;
    for (const auto &e : exp) {
        if (e >= '0' and e <= '9') num += e;
        else {
            if (e == '-' and first_of_subidx == -1) {
                first_of_subidx = opcnt;
            }
            opcnt++;
            nv.emplace_back(stoi(num));
            num.clear();
        }
    }
    nv.emplace_back(stoi(num));
    if (first_of_subidx == -1) cout << accumulate(nv.begin(), nv.end(), 0) << "\n";
    else cout << accumulate(nv.begin(), nv.begin() + first_of_subidx + 1, 0)
        - accumulate(nv.begin() + first_of_subidx + 1, nv.end(), 0) << "\n";
    return 0;
}