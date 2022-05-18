#include <bits/stdc++.h>
using namespace std;
bitset<int(1e7 + 1)> sieve;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    sieve.set();
    sieve.set(0, 0), sieve.set(1, 0);
    for (int i = 2; i * i <= 1e7; i++) {
        if (sieve[i]) {
            for (int j = i * i; j <= 1e7; j += i) {
                sieve.set(j, 0);
            }
        }
    }
    int a, b;
    cin >> a >> b;
    b = min(b, int(1e7));
    for (int i = a; i <= b; i++) {
        if (sieve[i]) {
            string src = to_string(i);
            string dst = src;
            reverse(dst.begin(), dst.end());
            if (dst == src) cout << i << "\n";
        }
    }
    cout << "-1\n";
    return 0;
}