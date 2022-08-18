#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, L; bool convertible = false;
    cin >> N >> L;
    for (int i = L; i <= 100; ++i) {
        if (i & 1) {
            if (N % i == 0) {
                int start = (N / i) - ((i - 1) / 2);
                if (start < 0) continue;
                convertible = true;
                for (int j = start; j < i + start; ++j) cout << j << " ";
                break;
            }
        }
        else {
            if ((N - (i * (i - 1) / 2)) % i == 0) {
                int start = (N - ((i - 1) * i / 2)) / i;
                if (start < 0) continue;
                convertible = true;
                for (int j = start; j < i + start; ++j) cout << j << " ";
                break;

            }
        }
    }
    if (!convertible) cout << "-1\n";
    return 0;
}