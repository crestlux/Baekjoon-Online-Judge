#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    vector<int> v(5); int cnt = 0, ret = 987654321;
    for (int i = 0; i < 5; i++) {
        cin >> v[i];
        ret = min(ret, v[i]);
    }
    while (1) {
        cnt = 0;
        for (int i = 0; i < 5; i++) {
            if (ret % v[i] == 0) cnt++;
        }
        if (cnt >= 3) break;
        else ret++;
    }
    cout << ret << "\n";
    return 0;
}