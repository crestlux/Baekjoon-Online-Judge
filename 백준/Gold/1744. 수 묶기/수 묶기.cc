#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; ll cur = 0, maxval = LLONG_MIN;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    if (N == 1) {
        maxval = v[0];
    }
    else if (N == 2) {
        maxval = max(v[0] + v[1], v[0] * v[1]);
    }
    else {
        int neg = -1, zero = -1, pos = -1;
        sort(v.begin(), v.end());
        for (int i = 0; i < N; i++) {
            if (neg == -1 && v[i] < 0) { neg = i; continue; }
            if (zero == -1 && v[i] == 0) { zero = i; continue; }
            if (pos == -1 && v[i] > 0) { pos = i; break; }
        }
        if (pos != -1) {
            for (int i = N - 1; i >= pos; i--) {
                if (i == pos) { cur += v[i]; break; }
                if (v[i] > 1 && v[i - 1] > 1) {
                    cur += v[i] * v[i - 1];
                    i--;
                    continue;
                }
                else {
                    cur += v[i] + v[i - 1] + max(i - 1 - pos, 0);
                    break;
                }
            }
        }
        if (zero != -1 && neg != -1) {
            for (int i = 0; i < zero; i += 2) {
                if (i == zero - 1) break;
                cur += v[i] * v[i + 1];
            }
        }
        if (zero == -1 && neg != -1) {
            int uplim = (pos == -1) ? N : pos;
            for (int i = 0; i < uplim; i += 2) {
                if (i == uplim - 1) { cur += v[i]; break; }
                cur += v[i] * v[i + 1];
            }
        }
        maxval = cur;
    }
    cout << maxval << "\n";
    return 0;
}