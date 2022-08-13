#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; bool chk = true; char c = 0;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        if (!i) c = s[0];
        else if (c != s[0]) {
            chk = false;
            break;
        }
    }
    cout << chk << "\n";
    return 0;
}