#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        double n, m; int cnt = 0;
        cin >> n >> m;
        for (int a = 1; a < n; a++) {
            for (int b = a + 1; b < n; b++) {
                double ret = (a * a + b * b + m) / (a * b);
                if (round(ret) == ret) cnt++;
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}