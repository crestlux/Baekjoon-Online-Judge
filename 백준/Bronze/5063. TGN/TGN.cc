#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, r, e, c;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> r >> e >> c;
        if (r < e - c) cout << "advertise\n";
        else if (r == e - c) cout << "does not matter\n";
        else cout << "do not advertise\n";
    }
    return 0;
}