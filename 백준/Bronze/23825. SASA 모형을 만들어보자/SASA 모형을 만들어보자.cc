#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    cout << min(N >> 1, M >> 1) << "\n";
    return 0;
}