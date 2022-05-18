#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    ull N, sum = 0;
    cin >> N;
    for (ull i = 1; i <= N; i++) {
        sum += (N / i) * i;
    }
    cout << sum << "\n";
    return 0;
}