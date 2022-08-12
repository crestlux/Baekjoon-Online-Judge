#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int y1, y2, m1, m2, d1, d2;
    cin >> y1 >> m1 >> d1 >> y2 >> m2 >> d2;
    auto ret = (sys_days{ (year(y2) / month(m2) / day(d2)) } - sys_days{ (year(y1) / month(m1) / day(d1)) }).count();
    bool mill = (y1 + 1000 < y2) or (y1 + 1000 == y2 and m1 < m2) or (y1 + 1000 == y2 and m1 == m2 and d1 <= d2);
    if (mill) cout << "gg\n";
    else cout << "D-" << ret << "\n";
    return 0;
}