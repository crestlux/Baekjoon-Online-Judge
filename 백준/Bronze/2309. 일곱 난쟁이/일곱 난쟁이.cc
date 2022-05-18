#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int height[9];
    for (int i = 0; i < 9; i++) {
        cin >> height[i];
    }
    sort(height, height + 9);
    while (1) {
        static size_t v = 0b001111111;
        size_t sum = 0, t = (v | (v - 1));
        for (int i = 0; i < 9; i++) {
            if (v & (1 << i)) sum += height[i];
        }
        if (sum == 100) {
            for (int i = 0; i < 9; i++) {
                if (v & (1 << i)) cout << height[i] << "\n";
            }
            break;
        }
        v = (t + 1) | (((~t & -~t) - 1) >> (__builtin_ctz(v) + 1));
    }
    return 0;
}