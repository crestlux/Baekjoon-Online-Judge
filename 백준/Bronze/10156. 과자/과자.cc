#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int K, N, M;
    cin >> K >> N >> M;
    int ret = K * N - M;
    ret < 0 ? cout << "0\n" : cout << ret << "\n";
    return 0;
}