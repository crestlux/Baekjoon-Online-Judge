#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    ll N; ll sum = 0;
    cin >> N;
    vector<ll> v(N);
    for (int i = 0; i < N; i++) { cin >> v[i]; sum += v[i]; }
    sum *= sum;
    for (int i = 0; i < N; i++) { sum -= (v[i] * v[i]); }
    sum >>= 1;
    cout << sum << "\n";
    return 0;
}