#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    vector<int> scoresum(6, 0);
    int tmp = 0, maxscore = -987654321, maxidx = -1;
    for (int i = 1; i <= 5; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> tmp;
            scoresum[i] += tmp;
        }
    }
    for (int i = 1; i <= 5; i++) {
        if (maxscore < scoresum[i]) {
            maxidx = i;
            maxscore = scoresum[i];
        }
    }
    cout << maxidx << " " << maxscore << "\n";
    return 0;
}