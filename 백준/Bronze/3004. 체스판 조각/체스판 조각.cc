#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N;
    cin >> N;
    if (N & 1) {
        cout << ((N + 1) >> 1) * (((N + 1) >> 1) + 1) << "\n";
    }
    else {
        cout << ((N >> 1) + 1) * ((N >> 1) + 1) << "\n";
    }
    return 0;
}