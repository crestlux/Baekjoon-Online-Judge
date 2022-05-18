#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        if (i & 1) {
            for (int j = 1; j <= N*2-1; j++) {
                if (j & 1) cout << "*";
                else cout << " ";
            }
            cout << "\n";
        }
        else {
            for (int j = 1; j <= N*2; j++) {
                if (j & 1) cout << " ";
                else cout << "*";
            }
            cout << "\n";
        }
    }
    return 0;
}