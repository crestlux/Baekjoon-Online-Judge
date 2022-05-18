#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int K, D1, D2;
    cin >> K >> D1 >> D2;
    cout << fixed; cout.precision(8);
    cout << K * K - (D1 - D2) * (D1 - D2) / 4.0 << "\n";
    return 0;
}