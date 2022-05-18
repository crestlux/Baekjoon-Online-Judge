#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int M, N, msq = 0, m = 0, sum = 0;
    cin >> M >> N;
    msq = ceil(sqrt(M));
    m = msq * msq;
    if (m > N) cout << "-1\n";
    else {
        for (int i = msq; i <= sqrt(N); i++) sum += i * i;
        cout << sum << "\n" << m << "\n";
    }
    return 0;
}