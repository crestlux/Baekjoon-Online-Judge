#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, H, ob, cnt = 0; double seg = 0.5;
    cin >> N >> H;
    vector<int> hi, lo;
    hi.reserve((N >> 1) + 1); lo.reserve((N >> 1) + 1);
    for (int i = 0; i < N; i++) {
        cin >> ob;
        if (i & 1) hi.push_back(H - ob);
        else lo.push_back(ob);
    }
    sort(hi.begin(), hi.end());
    sort(lo.begin(), lo.end());
    int dstry = 987654321;
    while (seg < H) {
        int cur_dstry = distance(upper_bound(lo.begin(), lo.end(), seg), lo.end()) + distance(hi.begin(), lower_bound(hi.begin(), hi.end(), seg));
        if (dstry > cur_dstry) {
            dstry = cur_dstry;
            cnt = 1;
        }
        else if (dstry == cur_dstry) cnt++;
        seg++;
    }
    cout << dstry << " " << cnt << "\n";
    return 0;
}