#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int A, B, C, elapsed;
    cin >> A >> B >> C >> elapsed;
    auto t = hh_mm_ss(hours(A) + minutes(B) + seconds(C) + seconds(elapsed));
    int h_ex = t.hours().count() / 24;
    if (t.hours().count() >= 24) t = hh_mm_ss(hours(A - 24 * h_ex) + minutes(B) + seconds(C) + seconds(elapsed));
    cout << t.hours().count() << " " << t.minutes().count() << " " << t.seconds().count() << "\n";
    return 0;
}