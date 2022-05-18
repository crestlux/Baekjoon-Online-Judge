#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M, ret = 0; char S; vector<int> v;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> S;
        if (S == 'I') v.push_back(i);
    }
    int vsize = v.size(), consec = 0;
    if (vsize >= N) {
        for (int i = 0; i < vsize - 1; i++) {
            if (v[i + 1] == v[i] + 2) {
                consec++;
                if (i == vsize - 2) {
                    int cnt = consec - N + 1;
                    if (cnt < 0) cnt = 0;
                    ret += cnt;
                    consec = 0;
                }
                continue;
            }
            else {
                int cnt = consec - N + 1;
                if (cnt < 0) cnt = 0;
                ret += cnt;
                consec = 0;
                continue;
            }
        }
    }
    cout << ret << "\n";
    return 0;
}