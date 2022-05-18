#include <bits/stdc++.h>
using namespace std;
constexpr int s_size = 1e4;
unsigned char sieve[(s_size + 7) / 8 + 1];
inline bool isPrime(int x) {
    return sieve[x >> 3] & (1 << (x & 7));
}
inline void setComposite(int x) {
    sieve[x >> 3] &= ~(1 << (x & 7));
}
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    memset(sieve, 255, sizeof(sieve));
    setComposite(0); setComposite(1);
    for (int i = 2; i * i <= s_size; i++) {
        if (isPrime(i)) {
            for (int j = i * i; j <= s_size; j += i) {
                setComposite(j);
            }
        }
    }
    int N;
    cin >> N;
    while (N--) {
        int temp, cur;
        cin >> temp;
        cur = temp >> 1;
        while (1) {
            if (isPrime(cur) && isPrime(temp - cur)) {
                cout << cur << " " << temp - cur << "\n";
                break;
            }
            else --cur;
        }
    }
    return 0;
}