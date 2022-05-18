#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    map<int, int> ax, ay; int tx, ty;
    for (int i = 0; i < 3; i++) {
        int x, y;
        cin >> x >> y;
        if (ax.find(x) == ax.end()) ax.insert({ x, 1 });
        else ax[x]++;
        if (ay.find(y) == ax.end()) ay.insert({ y, 1 });
        else ay[y]++;
    }
    for (const auto &it : ax) if (it.second == 1) tx = it.first;
    for (const auto &it : ay) if (it.second == 1) ty = it.first;
    cout << tx << " " << ty << "\n";
    return 0;
}