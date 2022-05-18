#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    double A, B, C;
    cin >> A >> B >> C;
    cout << static_cast<long long>(floor(max(A / B * C, A * B / C))) << "\n";
    return 0;
}