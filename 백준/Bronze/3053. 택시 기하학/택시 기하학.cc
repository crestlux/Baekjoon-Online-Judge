#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    constexpr double PI = numbers::pi;
    int R;
    cin >> R;
    cout << fixed; cout.precision(8);
    cout << double(R) * R * PI << "\n" << ((R << 1) * (R << 1) >> 1) << "\n";
    return 0;
}