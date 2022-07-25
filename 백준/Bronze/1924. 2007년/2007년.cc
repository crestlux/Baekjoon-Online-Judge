#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    string wd[] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
    int x, y;
    cin >> x >> y;
    year_month_day ret{ year(2007), month(x), day(y) };
    weekday w(ret);
    cout << wd[w.c_encoding()] << "\n";
    return 0;
}