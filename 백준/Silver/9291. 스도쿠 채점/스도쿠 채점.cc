#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        vector<vector<int>> v(9, vector<int>(9, 0)); bool chk = true;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                cin >> v[i][j];
            }
        }
        for (int i = 0; i < 9 && chk; ++i) {
            unordered_set<int> us(v[i].begin(), v[i].end());
            if (us.size() != 9) chk = false;
        }
        for (int i = 0; i < 9 && chk; ++i) {
            unordered_set<int> us;
            for (int y = 0; y < 9; ++y) {
                us.insert(v[y][i]);
            }
            if (us.size() != 9) chk = false;
        }
        pair<int, int> p[] = { {0,0},{3,0}, {6,0}, {3,0}, {3,3}, {3,6}, {6,0}, {6,3}, {6,6} };
        for (int i = 0; i < 9 && chk; ++i) {
            unordered_set<int> us;
            for (int y = p[i].second; y < p[i].second + 3; ++y) {
                for (int x = p[i].first; x < p[i].first + 3; ++x) {
                    us.insert(v[y][x]);
                }
            }
            if (us.size() != 9) chk = false;
        }
        if (chk) cout << "Case " << tc << ": CORRECT\n";
        else cout << "Case " << tc << ": INCORRECT\n";
    }
    return 0;
}