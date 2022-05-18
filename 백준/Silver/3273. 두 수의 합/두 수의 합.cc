#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n, x, cnt = 0, lcnt = 1, rcnt = 1;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    cin >> x;
    int l = 0, r = n - 1, sum = v[0] + v[n - 1];
    while (r < n && l <= r) {
        if (sum == x) {
            if (v[l] == v[r]) { cnt += ((r - l + 1) * (r - l) / 2); break; }
            else {
                while (v[l] == v[l + 1] || v[r] == v[r - 1]) {
                    if (v[l] == v[l + 1]) { ++lcnt; ++l; }
                    if (v[r] == v[r - 1]) { ++rcnt; --r; }
                }
                cnt += lcnt * rcnt;
                lcnt = 1, rcnt = 1;
                sum = sum + v[l + 1] - v[l];
                ++l;
            }
        }
        else if (sum > x) {
            sum = sum + v[r - 1] - v[r];
            --r;
        }
        else {
            sum = sum + v[l + 1] - v[l];
            ++l;
        }
    }
    cout << cnt << "\n";
    return 0;
}